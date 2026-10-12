/* storage 0x02382B1C runtime 0x037FA9B4 size 0xC wram ARM. No pool, no calls. */

unsigned int fn_02382B1C(void) {
    unsigned int psr;
    asm {
        MRS psr, CPSR
    }
    return psr & 0x1F;
}
