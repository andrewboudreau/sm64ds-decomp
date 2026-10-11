"""Assemble, and optionally compile, the ARM7 image and compare SHA-1.

    python arm7/build.py
    python arm7/build.py --swap
    python arm7/build.py --gen path\\to\\arm7.bin

The asm-only link uses arm7/arm7.lcf. --swap writes build/arm7.lcf with the
matched C objects inserted at their storage addresses.
"""
import argparse
import hashlib
import os
import shutil
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
REPO = HERE.parent
ASM = HERE / "asm"
BUILD = HERE / "build"

CRT0_OFF, CRT0_LEN = 0x0, 0x168
WRAM_OFF, WRAM_LEN = 0x168, 0xDF20
MAIN_OFF, MAIN_LEN = 0xE088, 0x16A84
TAIL_OFF, TAIL_LEN = 0x24B0C, 0x18
WRAM_BASE = 0x02380168
MAIN_BASE = 0x0238E088
IMAGE_LEN = 0x24B24

CFLAGS = [
    "-O4,s", "-proc", "arm7tdmi", "-interworking", "-fp", "soft",
    "-enum", "int", "-lang", "c99", "-char", "signed",
]


def tools_root():
    env = os.environ.get("ARM7_MW")
    candidates = []
    if env:
        candidates.append(Path(env))
    candidates.append(REPO.parent.parent / "decomp_SM64DS" / "tools" / "mwccarm")
    candidates.append(Path(r"C:\Users\issus\Documents\SGH\decomps\decomp_SM64DS\tools\mwccarm"))
    for path in candidates:
        if (path / "license.dat").is_file():
            return path
    raise SystemExit("mwccarm tree not found; set ARM7_MW")


def run(cmd, cwd):
    print("+", " ".join(str(c) for c in cmd))
    result = subprocess.run(cmd, cwd=str(cwd), text=True)
    if result.returncode != 0:
        raise SystemExit("command failed (%s)" % result.returncode)


def write_words(path, data, label=None):
    if len(data) % 4:
        raise SystemExit("%s length 0x%X is not a multiple of 4" % (path, len(data)))
    lines = [".section .text"]
    if label:
        lines.append(".global %s" % label)
        lines.append("%s:" % label)
    for i in range(0, len(data), 4):
        word = int.from_bytes(data[i:i + 4], "little")
        lines.append("\t.word 0x%08X" % word)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text("\n".join(lines) + "\n", encoding="utf-8", newline="\n")


def read_words(path):
    words = []
    for line in path.read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if line.startswith(".word"):
            words.append(int(line.split()[1], 0))
    data = b"".join(w.to_bytes(4, "little") for w in words)
    return data


def gen(bin_path):
    blob = Path(bin_path).read_bytes()
    if len(blob) != IMAGE_LEN:
        raise SystemExit("arm7.bin is 0x%X bytes, expected 0x%X" % (len(blob), IMAGE_LEN))
    write_words(ASM / "crt0.s", blob[CRT0_OFF:CRT0_OFF + CRT0_LEN], "_start")
    write_words(ASM / "wram.s", blob[WRAM_OFF:WRAM_OFF + WRAM_LEN])
    write_words(ASM / "main.s", blob[MAIN_OFF:MAIN_OFF + MAIN_LEN])
    write_words(ASM / "autoload.s", blob[TAIL_OFF:TAIL_OFF + TAIL_LEN])
    digest = hashlib.sha1(blob).hexdigest()
    (HERE / "arm7.sha1").write_text(digest + "\n", encoding="utf-8", newline="\n")
    print("generated asm, sha1", digest)


def manifest_files(name, single):
    """Shared single file (legacy) plus one file per job in <name>.d/ (no shared list to conflict on)."""
    files = [HERE / single] if (HERE / single).is_file() else []
    d = HERE / (name + ".d")
    if d.is_dir():
        files += sorted(d.glob("*.txt"))
    return files


def load_syms(swapped):
    """Absolute symbols from syms.d/*.txt, one `name = 0xADDR` per line; dupes must agree; swapped C symbols win."""
    syms = {"unk_38075A8": 0x038075A8}
    for f in manifest_files("syms", "syms.txt"):
        for line in f.read_text(encoding="utf-8").splitlines():
            line = line.split("#", 1)[0].strip().rstrip(";")
            if not line:
                continue
            name, value = [x.strip() for x in line.split("=")]
            value = int(value, 0)
            if syms.get(name, value) != value:
                raise SystemExit("symbol %s defined twice with different values (%s)" % (name, f.name))
            syms[name] = value
    return {k: v for k, v in sorted(syms.items()) if k not in swapped}


def load_swap():
    rows = []
    lines = []
    for f in manifest_files("swap", "swap.txt"):
        lines += f.read_text(encoding="utf-8").splitlines()
    for line in lines:
        line = line.split("#", 1)[0].strip()
        if not line:
            continue
        storage, size, symbol, source, region = line.split()
        rows.append({
            "storage": int(storage, 16),
            "size": int(size, 16),
            "symbol": symbol,
            "source": HERE / source,
            "region": region,
        })
    return rows


def region_parts(data, base, rows):
    """Split a region image around the C functions that land in it."""
    cuts = []
    for row in rows:
        off = row["storage"] - base
        if off < 0 or off + row["size"] > len(data):
            raise SystemExit("%s is outside this region" % row["symbol"])
        cuts.append((off, row["size"], row))
    cuts.sort()
    parts = []
    cursor = 0
    for off, size, row in cuts:
        if off < cursor:
            raise SystemExit("overlap at %s" % row["symbol"])
        parts.append(("asm", data[cursor:off]))
        parts.append(("c", row))
        cursor = off + size
    parts.append(("asm", data[cursor:]))
    return [part for part in parts if not (part[0] == "asm" and len(part[1]) == 0)]


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--gen", metavar="ARM7_BIN")
    parser.add_argument("--swap", action="store_true")
    args = parser.parse_args()
    if args.gen:
        gen(args.gen)
        return

    mw = tools_root()
    os.environ["LM_LICENSE_FILE"] = str(mw / "license.dat")
    os.environ.setdefault("MWCIncludes", str(REPO / "include"))
    cc = mw / "2004" / "b56" / "mwccarm.exe"
    asm = mw / "1.2" / "sp2p3" / "mwasmarm.exe"
    ld = mw / "1.2" / "sp2p3" / "mwldarm.exe"
    for tool in (cc, asm, ld):
        if not tool.is_file():
            raise SystemExit("missing " + str(tool))

    if BUILD.exists():
        shutil.rmtree(BUILD)
    BUILD.mkdir()

    pieces = {
        "crt0": [("asm", read_words(ASM / "crt0.s"))],
        "wram": [("asm", read_words(ASM / "wram.s"))],
        "main": [("asm", read_words(ASM / "main.s"))],
        "tail": [("asm", read_words(ASM / "autoload.s"))],
    }
    objects = []
    if args.swap:
        rows = load_swap()
        pieces["wram"] = region_parts(pieces["wram"][0][1], WRAM_BASE, [r for r in rows if r["region"] == "wram"])
        pieces["main"] = region_parts(pieces["main"][0][1], MAIN_BASE, [r for r in rows if r["region"] == "main"])

    asm_index = {"crt0": 0, "wram": 0, "main": 0, "tail": 0}
    lcf_objs = {"crt0": [], "wram": [], "main": [], "tail": []}
    for region, parts in pieces.items():
        for kind, payload in parts:
            if kind == "asm":
                name = "%s_%d" % (region, asm_index[region])
                asm_index[region] += 1
                src = BUILD / (name + ".s")
                # _start is the first byte of crt0 and nowhere else.
                label = "_start" if region == "crt0" and asm_index[region] == 1 else None
                write_words(src, payload, label)
                obj = BUILD / (name + ".o")
                run([str(asm), "-proc", "arm4t", "-o", str(obj), str(src)], HERE)
                objects.append(obj.name)
                lcf_objs[region].append(obj.name)
            else:
                row = payload
                obj = BUILD / (row["symbol"] + ".o")
                run([str(cc), *CFLAGS, "-c", "-o", str(obj), str(row["source"])], HERE)
                objects.append(obj.name)
                lcf_objs[region].append(obj.name)

    lengths = {"crt0": CRT0_LEN, "wram": WRAM_LEN, "main": MAIN_LEN, "tail": TAIL_LEN}
    lcf = BUILD / "arm7.lcf"
    if args.swap:
        origins = {
            "crt0": "0x02380000",
            "wram": "0x037F8000",
            "main": "0x027C0000",
            "tail": "0x023A4B0C",
        }
        lines = ["MEMORY {"]
        for region, length in lengths.items():
            lines.append("    %s : ORIGIN = %s, LENGTH = 0x%X > %s.bin" % (region, origins[region], length, region))
        swapped = {r["symbol"] for r in load_swap()}
        lines += ["}", "", "SECTIONS {"]
        lines += ["    %s = 0x%08X;" % kv for kv in load_syms(swapped).items()]
        lines.append("")
        for region in ("crt0", "wram", "main", "tail"):
            lines.append("    .%s : {" % region)
            for name in lcf_objs[region]:
                lines.append("        %s(.text)" % name)
            lines.append("    } > %s" % region)
            lines.append("")
        lines.append("}")
        lcf.write_text("\n".join(lines) + "\n", encoding="utf-8", newline="\n")
    else:
        shutil.copyfile(HERE / "arm7.lcf", lcf)

    run([str(ld), "-proc", "v4t", "-nostdlib", "-interworking", "-m", "_start",
         "-nodead", "-msgstyle", "gcc", "-o", "arm7.elf", "arm7.lcf", *objects], BUILD)

    image = b""
    for region, length in lengths.items():
        blob = (BUILD / (region + ".bin")).read_bytes()
        if len(blob) != length:
            raise SystemExit("%s.bin is 0x%X, expected 0x%X" % (region, len(blob), length))
        image += blob
    out = BUILD / "arm7.bin"
    out.write_bytes(image)
    digest = hashlib.sha1(image).hexdigest()
    expect = (HERE / "arm7.sha1").read_text(encoding="utf-8").strip()
    print("sha1", digest)
    if digest != expect:
        raise SystemExit("SHA-1 mismatch: got %s expected %s" % (digest, expect))
    print("SHA-1 matches", expect)


if __name__ == "__main__":
    main()
