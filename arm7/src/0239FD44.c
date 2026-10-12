/* Hand-asm: scratch-reg assignment order (r2=&dat/r1=*dat) unreachable from C.
   Pool: 0x380FFF4, 0x508, 0x48080AC, 0x48080AE. */
extern int *dat_0380FFF4;
extern void fn_0239D638(int, void *);
extern int fn_0239A650(int);
extern int fn_023A07BC(int);

asm int fn_0239FD44(int a1, int a2)
{
    stmfd sp!, {r4, lr}
    mov r3, r0
    mov r4, r1
    ldr r2, =dat_0380FFF4
    ldr r1, [r2]
    ldr r0, =0x508
    ldr r0, [r1, r0]!
    add r0, r0, #1
    str r0, [r1]
    ldr r0, [r2]
    add r0, r0, #0x170
    sub r1, r3, #0x10
    bl fn_0239D638
    mov r1, #0
    ldr r2, =dat_0380FFF4
    ldr r0, [r2]
    add r0, r0, #0x400
    strh r1, [r0, #0xC]
    ldr r0, [r2]
    ldr r0, [r0, #0x414]
    ldrh r0, [r0, #0xC]
    mov r0, r0, lsl #0x12
    movs r0, r0, lsr #0x1F
    bne loc_BC
    mov r1, #8
    ldr r0, =0x48080AC
    strh r1, [r0]
    mov r1, #5
    ldr r0, =0x48080AE
    strh r1, [r0]
    cmp r4, #0
    beq loc_BC
    ldr r0, [r2]
    add r0, r0, #0x100
    ldrh r0, [r0, #0x6C]
    cmp r0, #0
    beq loc_9C
    mov r0, #1
    bl fn_023A07BC
loc_9C:
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    add r0, r0, #0x100
    ldrh r0, [r0, #0x60]
    cmp r0, #0
    beq loc_BC
    mov r0, #0
    bl fn_023A07BC
loc_BC:
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    add r0, r0, #0x100
    ldrh r0, [r0, #0x78]
    cmp r0, #0
    beq loc_E8
    cmp r4, #0
    beq loc_F0
    mov r0, #2
    bl fn_023A07BC
    b loc_F0
loc_E8:
    mov r0, #0
    bl fn_0239A650
loc_F0:
    ldmfd sp!, {r4, lr}
    bx lr
}
