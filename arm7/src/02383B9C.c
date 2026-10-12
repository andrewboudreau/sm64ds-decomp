/* Hand-asm: mwcc always emits the stack-arg stores low-to-high ([sp],[sp+4],
   [sp+8]); the ROM schedules them cb->[sp+4], 0->[sp+8], 0->[sp] with the
   0xAA8 load interleaved. Pool +0x4C: fn_02383B08, 0xAA8, dat_038070FC. */
extern unsigned long long fn_02381EB0(void);
extern int fn_0238222C(int *, unsigned long long, int, int, void (*)(void), int);
extern int dat_038070FC;
extern void fn_02383B08(void);

asm int fn_02383B9C(void)
{
    stmfd sp!, {lr}
    sub sp, sp, #0xC
    bl fn_02381EB0
    mov ip, r0
    ldr r0, =fn_02383B08
    str r0, [sp, #4]
    mov r0, #0
    str r0, [sp, #8]
    ldr r3, =0xAA8
    str r0, [sp]
    ldr r0, =dat_038070FC
    mov r2, #0x10000
    adds ip, ip, r2
    adc r2, r1, #0
    mov r1, ip
    bl fn_0238222C
    add sp, sp, #0xC
    ldmfd sp!, {lr}
    bx lr
}
