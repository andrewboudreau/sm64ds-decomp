/* Hand-asm: w1 rides LR across the table lookup (mwccarm never selects lr as
   scratch in a leaf). Pool +0x5C: dat_03805960. */
extern unsigned char dat_03805960[];

asm int fn_02383EBC(unsigned short *a1, unsigned short *a2)
{
    stmfd sp!, {lr}
    sub sp, sp, #4
    ldrh lr, [r0, #0x24]
    and r2, lr, #0xFF
    ldrh ip, [r1, #0x24]
    and r0, ip, #0xFF
    mov r2, r2, lsl #4
    mov r3, r0, lsl #4
    ldr r1, =dat_03805960
    ldrb r0, [r1, lr, asr #8]
    mov r2, r2, asr r0
    ldrb r0, [r1, ip, asr #8]
    mov r0, r3, asr r0
    cmp r2, r0
    beq eq
    cmp r2, r0
    movlt r0, #1
    mvnge r0, #0
    b out
eq:
    mov r0, #0
out:
    add sp, sp, #4
    ldmfd sp!, {lr}
    bx lr
}
