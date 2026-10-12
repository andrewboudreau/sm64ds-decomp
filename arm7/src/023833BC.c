/* storage 0x023833BC runtime 0x037FB254 size 0x10 wram ARM.
 * ARM->Thumb interworking veneer (linker long-call stub) to Thumb
 * 0x037FFFF2: LDR IP,=0x4D93 / ADD IP,PC,IP / BX IP + pool.
 * Whole-asm so no C prologue (AM24 fn_02388CD8 precedent: no C construct
 * emits ADD IP,PC,IP; AM11 classified it not C-expressible). No BL; pool
 * word is a pc-relative offset (numeric, not ABS32). IDA-verified. */

asm void fn_023833BC(void) {
    LDR IP, =0x4D93
    ADD IP, PC, IP
    BX IP
}
