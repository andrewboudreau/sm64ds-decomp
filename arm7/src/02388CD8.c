/* storage 0x02388CD8 runtime 0x03800B70 size 0x10 wram ARM.
 * Thunk like fn_02380594: LDR R12,=0xFFFFF451 / ADD R12,PC,R12 / BX R12
 * (targets 0x037FFFCD, Thumb). Whole-asm so no BX LR epilogue. Takes an int
 * (all in-pack callers pass R0, e.g. 1); the asm body ignores it. */

asm void fn_02388CD8(int a1) {
    LDR R12, =0xFFFFF451
    ADD R12, PC, R12
    BX R12
}
