/* Hand-asm: &dat/0xFFFF/0x1C scratch-reg assignment is unreachable from C.
   Pool: 0x380FFF4, 0x4E8, 0xFFFF, unk_27D680C. */
extern int *dat_0380FFF4;
extern void fn_02382C80(int, void *, int);
extern int fn_0239A284(int, void *);
extern int fn_0239A98C(int, int);
extern unsigned short unk_27D680C[];

asm int fn_0239A434(void)
{
    stmfd sp!, {r4, lr}
    sub sp, sp, #8
    ldr r0, =dat_0380FFF4
    ldr r2, [r0]
    ldr r4, [r2, #0x2E0]
    mov r0, #0
    strh r0, [sp]
    ldrh r0, [sp]
    mov r1, r4
    add r2, r2, #0x200
    ldrh r3, [r2, #0xE6]
    mov r2, #0x1C
    mul r2, r3, r2
    bl fn_02382C80
    mov r0, #0
    strh r0, [sp, #2]
    ldrh r0, [sp, #2]
    ldr r1, =dat_0380FFF4
    ldr r2, [r1]
    ldr r1, =0x4E8
    add r1, r2, r1
    mov r2, #0xC
    bl fn_02382C80
    ldr r3, =0xFFFF
    strh r3, [r4, #0x1A]
    mov ip, #1
    ldr r2, =dat_0380FFF4
    mov r1, #0x1C
    b loc_42C
loc_420:
    mla r0, ip, r1, r4
    strh r3, [r0, #0x1A]
    add ip, ip, #1
loc_42C:
    ldr r0, [r2]
    add r0, r0, #0x200
    ldrh r0, [r0, #0xE6]
    cmp ip, r0
    bcc loc_420
    mov r0, #0
    ldr r1, =unk_27D680C
    bl fn_0239A284
    mov r0, #0
    mov r1, #0x40
    bl fn_0239A98C
    add sp, sp, #8
    ldmfd sp!, {r4, lr}
    bx lr
}
