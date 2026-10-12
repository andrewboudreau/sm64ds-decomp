/* Hand-asm: +0x300 chain/result r0-r1 rotation is unreachable from C.
   Pool: 0x380FFF4, 0xFFFF, 0x4E8. */
extern int *dat_0380FFF4;
extern void fn_0239F9AC(int);
extern void fn_0239B6F0(void *, int);
extern void fn_023969F4(int);
extern void fn_02396A98(void);
extern int fn_0239A98C(int, int);

asm void fn_0239A4FC(void)
{
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #4
    ldr r6, =dat_0380FFF4
    ldr r1, [r6]
    ldr r0, [r1, #0x2E0]
    add r10, r0, #0x1C
    add r0, r1, #0x400
    ldrh r7, [r0, #0xE8]
    cmp r7, #1
    bls loc_540
    mov r8, #0
    mov r9, #1
    mov r5, #0x20
    str r9, [sp]
    mov r11, r9
    mov r4, r8
    b loc_52C
loc_448:
    ldrh r0, [r10]
    cmp r0, #0
    beq loc_524
    ldrh r1, [r10, #0x18]
    cmp r1, #0
    beq loc_518
    ldr r0, =0xFFFF
    cmp r1, r0
    beq loc_518
    add r1, r10, #0x18
    ldrh r0, [r1]
    sub r0, r0, #1
    strh r0, [r1]
    ldrh r0, [r10, #0x18]
    cmp r0, #0
    bne loc_518
    ldrh r0, [r10]
    cmp r0, #0x20
    bcc loc_500
    mov r0, r9
    bl fn_0239F9AC
    ldr r0, [r6]
    add r0, r0, #0x300
    ldrh r1, [r0, #0x14]
    cmp r1, #1
    bne loc_4CC
    ldrh r0, [r10]
    cmp r0, #0x20
    bls loc_4F0
    add r0, r10, #4
    mov r1, r11
    bl fn_0239B6F0
    b loc_4F0
loc_4CC:
    ldrh r0, [r0, #0x84]
    cmp r9, r0
    bne loc_4F0
    mov r0, r5
    bl fn_023969F4
    bl fn_02396A98
    add r0, r10, #4
    ldr r1, [sp]
    bl fn_0239B6F0
loc_4F0:
    mov r0, r9, lsl #0x10
    mov r0, r0, lsr #0x10
    mov r1, r5
    bl fn_0239A98C
loc_500:
    strh r4, [r10]
    ldr r1, [r6]
    ldr r0, =0x4E8
    ldrh r0, [r1, r0]!
    sub r0, r0, #1
    strh r0, [r1]
loc_518:
    add r8, r8, #1
    cmp r8, r7
    bcs loc_540
loc_524:
    add r9, r9, #1
    add r10, r10, #0x1C
loc_52C:
    ldr r0, [r6]
    add r0, r0, #0x200
    ldrh r0, [r0, #0xE6]
    cmp r9, r0
    bcc loc_448
loc_540:
    add sp, sp, #4
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
}
