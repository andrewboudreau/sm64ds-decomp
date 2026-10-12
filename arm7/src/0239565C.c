/* Hand-asm: mwcc always schedules the stack-arg stores low-to-high and keeps
   the 64-bit add result in ip/r3; the ROM materializes 0 in ip, does the add
   into lr, then stores the stack args middle-out ([sp+4], [sp+8], [sp]) with
   the argument moves interleaved. Pool +0x6C: dat_0380FFF4, 0x82EA. */
extern int *dat_0380FFF4;
extern int fn_0238219C(int);
extern unsigned long long fn_02381EB0(void);
extern int fn_0238222C(int, int, int, int, int, int, int);

asm int fn_0239565C(int a1, int a2)
{
    stmfd sp!, {r4, r5, lr}
    sub sp, sp, #0xC
    mov r5, r0
    mov r4, r1
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    add r0, r0, #0x5C0
    bl fn_0238219C
    ldr r0, =0x82EA
    mul r0, r5, r0
    mov r5, r0, lsr #6
    bl fn_02381EB0
    mov ip, #0
    adds lr, r5, r0
    adc r2, r1, #0
    str r4, [sp, #4]
    str ip, [sp, #8]
    mov r3, r5
    str ip, [sp]
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    add r0, r0, #0x5C0
    mov r1, lr
    bl fn_0238222C
    add sp, sp, #0xC
    ldmfd sp!, {r4, r5, lr}
    bx lr
}
