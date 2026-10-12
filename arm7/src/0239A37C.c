/* Hand-asm: the first field store reuses r1 from the loop-exit test (no
   reload of *v0) — a cross-edge schedule C won't emit.
   Pool: 0x380FFF4, 0xFFFE. */
extern int *dat_0380FFF4;
extern void fn_02382C80(int, void *, int);

asm int fn_0239A37C(void)
{
    stmfd sp!, {r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #4
    ldr r6, =dat_0380FFF4
    ldr r0, [r6]
    ldr r8, [r0, #0x2E0]
    mov r7, #1
    mov r5, #0
    mov r4, #0x1A
    mov r9, #0x1C
    b loc_334
loc_31C:
    strh r5, [sp]
    ldrh r0, [sp]
    mla r1, r7, r9, r8
    mov r2, r4
    bl fn_02382C80
    add r7, r7, #1
loc_334:
    ldr r1, [r6]
    add r0, r1, #0x200
    ldrh r0, [r0, #0xE6]
    cmp r7, r0
    bcc loc_31C
    mov r0, #1
    add r1, r1, #0x400
    strh r0, [r1, #0xE8]
    mov r3, #0
    ldr r1, [r6]
    add r1, r1, #0x400
    strh r3, [r1, #0xEA]
    ldr r1, [r6]
    add r1, r1, #0x400
    strh r0, [r1, #0xEC]
    ldr r2, =0xFFFE
    ldr r1, [r6]
    add r1, r1, #0x400
    strh r2, [r1, #0xEE]
    ldr r1, [r6]
    add r1, r1, #0x400
    strh r3, [r1, #0xF0]
    ldr r1, [r6]
    add r1, r1, #0x400
    strh r0, [r1, #0xF2]
    add sp, sp, #4
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, lr}
    bx lr
}
