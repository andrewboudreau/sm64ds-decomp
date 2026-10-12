/* Hand-asm: the register allocation (a1->r5, a2->r4, i->r6, 0->r7, result in
   r0 only) needs exactly 4 callee-saved regs; mwcc insists on a fifth for the
   shared 'result' local under every spelling tried. Pools +0xD8: 0x4000006,
   dat_038087A0. */
extern int fn_02387C40(unsigned short *);
extern int fn_02387BD4(int);
extern int fn_02382B28(int);
extern int *dat_038087A0;

asm int fn_02387AE4(int a1, int a2)
{
    stmfd sp!, {r4, r5, r6, r7, lr}
    sub sp, sp, #0x14
    mov r5, r0
    mov r4, r1
    mov r6, #1
    adds r0, r5, r4
    beq tail
    cmp r5, #0
    beq next
    ldr r0, =0x4000006
    ldrh r0, [r0]
    strh r0, [sp]
    str r5, [sp, #4]
    mov r7, #0
    add r6, sp, #0
    b t1
l1:
    mov r0, r7
    bl fn_02382B28
t1:
    mov r0, r6
    bl fn_02387C40
    cmp r0, #0
    bne l1
next:
    cmp r4, #0
    beq els
    ldr r0, =0x4000006
    ldrh r0, [r0]
    strh r0, [sp, #8]
    sub r0, r4, r5
    str r0, [sp, #0xC]
    mov r6, #0
    add r4, sp, #8
    mov r5, r6
    b t2
b2:
    mov r0, r5
    bl fn_02382B28
    bl fn_02387BD4
    mov r6, r0
t2:
    cmp r6, #0
    bne tail
    mov r0, r4
    bl fn_02387C40
    cmp r0, #0
    bne b2
    b tail
els:
    bl fn_02387BD4
    mov r6, r0
tail:
    cmp r6, #0
    moveq r1, #4
    ldreq r0, =dat_038087A0
    ldreq r0, [r0]
    streq r1, [r0]
    add sp, sp, #0x14
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
}
