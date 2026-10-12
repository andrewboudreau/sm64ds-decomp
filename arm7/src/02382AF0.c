/* storage 0x02382AF0 runtime 0x037FA988 size 0x14 wram ARM. No pool, no calls. */

int fn_02382AF0(void) {
    int old, tmp;
    asm {
        MRS old, CPSR
        ORR tmp, old, #0xC0
        MSR CPSR_c, tmp
        AND old, old, #0xC0
    }
    return old;
}
