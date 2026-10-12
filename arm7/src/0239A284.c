/* Hand-asm: the &dat/chain r0-r1 rotation past the third call is
   unreachable from C.
   Pool: 0x380FFF4, 0x4E8, 0x4EC, 0xFFFF. */
extern int *dat_0380FFF4;
extern void fn_02382C80(int, void *, int);
extern int fn_0239A8F8(int, int);
extern void fn_023969D8(void *, void *);
extern int fn_0239A98C(int, int);

asm void fn_0239A284(int a1, void *a2)
{
    stmfd sp!, {r4, r5, r6, lr}
    sub sp, sp, #8
    mov r6, r0
    mov r5, r1
    ldr r0, =dat_0380FFF4
    ldr r2, [r0]
    ldr r1, [r2, #0x2E0]
    mov r0, #0x1C
    mul r0, r6, r0
    add r4, r1, r0
    ldrh r0, [r1, r0]
    cmp r0, #0
    ldreq r0, =0x4E8
    addeq r1, r2, r0
    ldreqh r0, [r1]
    addeq r0, r0, #1
    streqh r0, [r1]
    mov r0, #0
    strh r0, [sp]
    ldrh r0, [sp]
    mov r1, r4
    mov r2, #0x1A
    bl fn_02382C80
    mov r0, r6, lsl #0x10
    mov r0, r0, lsr #0x10
    mov r1, #0
    bl fn_0239A8F8
    ldr r0, =dat_0380FFF4
    ldr r1, [r0]
    ldr r0, =0x4EC
    add r2, r1, r0
    ldrh r1, [r2]
    mov r0, #1
    orr r0, r1, r0, lsl r6
    strh r0, [r2]
    add r0, r4, #4
    mov r1, r5
    bl fn_023969D8
    ldr r0, =0xFFFF
    strh r0, [r4, #0x14]
    ldr r1, =dat_0380FFF4
    ldr r0, [r1]
    add r0, r0, #0x300
    ldrh r0, [r0, #0x5E]
    strh r0, [r4, #0x10]
    ldr r0, [r1]
    add r0, r0, #0x300
    ldrh r0, [r0, #0x74]
    strh r0, [r4, #0x12]
    ldrh r0, [r4, #0x1A]
    strh r0, [r4, #0x18]
    mov r0, r6, lsl #0x10
    mov r0, r0, lsr #0x10
    mov r1, #0x20
    bl fn_0239A98C
    add sp, sp, #8
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
}
