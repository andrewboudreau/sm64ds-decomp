/* storage 0x02382AD8 runtime 0x037FA970 size 0x18 wram ARM.
 * Restore CPSR I-bit from argument, return previous I-bit. MRS/MSR are not
 * expressible in plain C; inline asm per the ARMProcessorMode.c precedent. */

int fn_02382AD8(int a1) {
    int tmp;
    int old;
    int ret;
    asm {
        mrs old, cpsr
        bic tmp, old, #0x80
        orr tmp, tmp, a1
        msr cpsr_c, tmp
        and ret, old, #0x80
    }
    return ret;
}
