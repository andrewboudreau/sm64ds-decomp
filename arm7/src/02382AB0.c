/* storage 0x02382AB0 runtime 0x037FA948 size 0x14 wram ARM.
 * Clear CPSR I-bit (enable IRQ), return previous I-bit. MRS/MSR are not
 * expressible in plain C; inline asm per the ARMProcessorMode.c precedent. */

int fn_02382AB0(void) {
    int old;
    int tmp;
    asm {
        mrs old, cpsr
        bic tmp, old, #0x80
        msr cpsr_c, tmp
        and old, old, #0x80
    }
    return old;
}
