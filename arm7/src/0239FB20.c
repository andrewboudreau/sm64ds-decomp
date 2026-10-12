/* Hand-asm: `bx r2` indirect handler call (`mov lr,pc`) unreachable from C. */
extern int *dat_0380FFF4;

void fn_0239FB20(void);
asm void fn_0239FB20(void)
{
    stmfd sp!, {lr}
    sub sp, sp, #4
    ldr r1, =dat_0380FFF4
    ldr r1, [r1]
    add r2, r1, #0x3E4
    mov r1, #0x14
    mul r1, r0, r1
    add r3, r2, r1
    ldrh r0, [r2, r1]
    cmp r0, #0
    beq _done
    ldr r0, [r3, #8]
    ldrh r1, [r0]
    cmp r1, #0
    moveq r1, #2
    ldreq r0, [r3, #0xC]
    streqh r1, [r0, #8]
    ldrne r0, [r3, #0xC]
    strneh r1, [r0, #8]
    ldr r0, [r3, #0xC]
    mov r1, #0
    ldr r2, [r3, #0x10]
    mov lr, pc
    bx r2
_done:
    add sp, sp, #4
    ldmfd sp!, {lr}
    bx lr
}
