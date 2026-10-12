/* Hand-asm: every C form parks &dat_0380FFF4 in r2 and the field chain in
   r1; the ROM wants them swapped across the whole body.
   Pool: 0x380FFF4, 0x4F2. */
extern int *dat_0380FFF4;
extern int fn_02396CF0(void);

asm int fn_0239A7A4(int a1)
{
    stmfd sp!, {lr}
    sub sp, sp, #4
    ldr r1, =dat_0380FFF4
    ldr r2, [r1]
    ldr r2, [r2, #0x2E0]
    add r3, r2, #2
    mov r2, #0x1C
    mul r2, r0, r2
    mov lr, #1
    ldrh ip, [r3, r2]
    mov r0, #0
    strh r0, [r3, r2]
    ldr r2, [r1]
    ldr r0, =0x4F2
    add r3, r2, r0
    ldrh r2, [r3]
    mvn r0, lr, lsl ip
    and r0, r2, r0
    strh r0, [r3]
    ldr r0, [r1]
    add r2, r0, #0x4F0
    ldrh r0, [r2]
    sub r0, r0, #1
    strh r0, [r2]
    ldr r0, [r1]
    add r0, r0, #0x400
    ldrh r0, [r0, #0xF0]
    cmp r0, #0
    bne loc_794
    bl fn_02396CF0
loc_794:
    add sp, sp, #4
    ldmfd sp!, {lr}
    bx lr
}
