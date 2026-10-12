/* Hand-asm: +0xC/-7 and +0xC/-1 split field arithmetic folds back to
   +5/+0xB in C; reg order in the MMIO block unreachable.
   Pool: 0xFFFF, 0x4808044, 0x380FFF4, 0xB6B8, 0x1D46. */
extern int *dat_0380FFF4;
extern void fn_02395388(void *, void *, int);
extern void fn_023953C4(void *, void *, int);
extern int fn_02395400(void *, int);

asm int fn_023A05A4(int a1, int a2)
{
    stmfd sp!, {r4, r5, lr}
    sub sp, sp, #4
    mov r5, r0
    add r4, r1, #0x10
    ldrh r2, [r4, #0x14]
    ands r2, r2, #0x4000
    beq loc_BC
    ldrh r2, [r1, #0xC]
    ldr r1, =0xFFFF
    cmp r2, r1
    bne loc_40
    add r1, r4, #8
    add r2, r4, #0x2C
    ldrh r3, [r4, #6]
    bl fn_02395388
    b loc_50
loc_40:
    add r1, r4, #8
    ldr r2, [r4, #0x2C]
    ldrh r3, [r4, #6]
    bl fn_02395388
loc_50:
    ldr r2, =0x4808044
    ldrh r1, [r2]
    ldrh r0, [r2]
    add r0, r1, r0, lsl #8
    strh r0, [r5, #0x24]
    ldrh r0, [r2]
    and r2, r0, #0xFF
    ldr r1, =dat_0380FFF4
    ldr r0, [r1]
    add r0, r0, #0x200
    ldrh r0, [r0, #0xFA]
    orr r0, r2, r0, lsl #14
    strh r0, [r5, #0x26]
    ldr r0, [r1]
    add r0, r0, #0x600
    ldrh r0, [r0, #0x1C]
    ands r0, r0, #8
    beq loc_F0
    add r1, r5, #0xC
    ldrh r0, [r4, #0x12]
    add r0, r1, r0
    sub r0, r0, #7
    bic r1, r0, #1
    mov r0, #0
    strh r0, [r1]
    strh r0, [r1, #2]
    b loc_F0
loc_BC:
    ldrh r2, [r1, #0xC]
    ldr r1, =0xFFFF
    cmp r2, r1
    bne loc_E0
    add r1, r4, #8
    ldrh r2, [r4, #6]
    add r2, r2, #0x24
    bl fn_02395400
    b loc_F0
loc_E0:
    add r1, r4, #8
    ldr r2, [r4, #0x2C]
    ldrh r3, [r4, #6]
    bl fn_023953C4
loc_F0:
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    add r0, r0, #0x600
    ldrh r0, [r0, #0x1C]
    ands r0, r0, #4
    beq loc_12C
    add r1, r5, #0xC
    ldrh r0, [r4, #0x12]
    add r0, r1, r0
    sub r0, r0, #1
    bic r1, r0, #3
    ldr r0, =0xB6B8
    strh r0, [r1]
    ldr r0, =0x1D46
    strh r0, [r1, #2]
loc_12C:
    add sp, sp, #4
    ldmfd sp!, {r4, r5, lr}
    bx lr
}
