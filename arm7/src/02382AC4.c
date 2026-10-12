/* storage 0x02382AC4 runtime 0x037FA95C size 0x14 wram ARM.
 * Set CPSR I-bit (disable IRQ), return previous I-bit. MRS/MSR are not
 * expressible in plain C; inline asm per the ARMProcessorMode.c precedent. */

int fn_02382AC4(void) {
    int old;
    int tmp;
    asm {
        mrs old, cpsr
        orr tmp, old, #0x80
        msr cpsr_c, tmp
        and old, old, #0x80
    }
    return old;
}
