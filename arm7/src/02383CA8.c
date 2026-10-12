asm int fn_02383CA8(int a1, char a2, int a3, short a4, int a5, int a6, int a7)
{
    stmfd sp!, {r4, r5, lr}
    sub sp, sp, #4
    mov r4, r0, lsl #3
    ldr ip, [sp, #0x10]
    cmp ip, #0
    movne r5, #0
    moveq r5, #1
    ldr lr, [sp, #0x18]
    ldr ip, [sp, #0x14]
    mov r1, r1, lsl #3
    orr r1, r1, r5, lsl #2
    orr r1, r1, ip, lsl #1
    orr r1, lr, r1
    add r0, r0, #0x4000000
    strb r1, [r0, #0x508]
    add r0, r4, #0x4000000
    str r2, [r0, #0x510]
    add r0, r0, #0x500
    strh r3, [r0, #0x14]
    add sp, sp, #4
    ldmfd sp!, {r4, r5, lr}
    bx lr
}
