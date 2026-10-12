/* Hand-asm: cond-exec counter blocks, out-of-line ++v4[1] island and scratch
   reg order unreachable from C.
   Pool: 0x380FFF4, 0x4F4, 0x4EC, 0xFFFE. */
extern int *dat_0380FFF4;
extern void fn_0239AAA8(int);
extern void fn_0239D638(int, void *);
extern int fn_023A07BC(int);
extern void fn_02396EFC(int);

asm int fn_023A0398(unsigned short *a1, int a2)
{
    stmfd sp!, {r4, r5, r6, r7, lr}
    sub sp, sp, #4
    mov r7, r0
    mov r6, r1
    ldr r1, =dat_0380FFF4
    ldr r2, [r1]
    ldr r1, =0x4F4
    add r5, r2, r1
    sub r4, r7, #0x10
    bl fn_0239AAA8
    ldrh r0, [r7, #8]
    ands r0, r0, #2
    bne loc_A8
    ldr r0, [r5]
    add r0, r0, #1
    str r0, [r5]
    ldrh r0, [r7, #0x14]
    mov r0, r0, lsl #0x17
    movs r0, r0, lsr #0x1F
    beq loc_7C
    ldrh r0, [r7, #0x24]
    ands r0, r0, #1
    addne r1, r5, #0x14
    ldrne r0, [r1]
    addne r0, r0, #1
    strne r0, [r1]
    addeq r1, r5, #0x10
    ldreq r0, [r1]
    addeq r0, r0, #1
    streq r0, [r1]
    b loc_B8
loc_7C:
    ldrh r0, [r7, #0x18]
    ands r0, r0, #1
    addne r1, r5, #0x14
    ldrne r0, [r1]
    addne r0, r0, #1
    strne r0, [r1]
    addeq r1, r5, #0x10
    ldreq r0, [r1]
    addeq r0, r0, #1
    streq r0, [r1]
    b loc_B8
loc_A8:
    add r1, r5, #4
    ldr r0, [r1]
    add r0, r0, #1
    str r0, [r1]
loc_B8:
    ldrh r0, [r7, #0x14]
    mov r0, r0, lsl #0x11
    movs r0, r0, lsr #0x1F
    addne r1, r5, #0x18
    ldrne r0, [r1]
    addne r0, r0, #1
    strne r0, [r1]
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    add r0, r0, #0x158
    mov r1, r4
    bl fn_0239D638
    mov r1, #0
    ldr r2, =dat_0380FFF4
    ldr r0, [r2]
    add r0, r0, #0x300
    strh r1, [r0, #0xE4]
    ldrh r1, [r7, #2]
    ldr r0, [r2]
    add r2, r0, #0x400
    ldrh r2, [r2, #0xEA]
    mov r2, r2, asr r1
    ands r2, r2, #1
    beq loc_158
    ldrh r2, [r7, #0x14]
    ands r2, r2, #0x2000
    bne loc_158
    ldr r3, [r0, #0x2E0]
    mov r2, #0x1C
    mul r2, r1, r2
    ldrh r2, [r3, r2]
    cmp r2, #0x40
    bne loc_158
    ldr r2, =0x4EC
    add r3, r0, r2
    ldrh r2, [r3]
    mov r0, #1
    mvn r0, r0, lsl r1
    and r0, r2, r0
    strh r0, [r3]
loc_158:
    cmp r6, #0
    beq loc_1F0
    ldr r0, =dat_0380FFF4
    ldr r3, [r0]
    add r0, r3, #0x100
    ldrh r0, [r0, #0x60]
    cmp r0, #0
    beq loc_184
    mov r0, #0
    bl fn_023A07BC
    b loc_1F0
loc_184:
    add r1, r3, #0x300
    ldrh r2, [r1, #0x14]
    ldr r0, =0xFFFE
    add r0, r2, r0
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    cmp r0, #1
    bhi loc_1F0
    ldrh r0, [r1, #0x10]
    cmp r0, #0x40
    bne loc_1F0
    ldrh r0, [r1, #0x16]
    mov r0, r0, lsl #0x1F
    movs r0, r0, lsr #0x1F
    beq loc_1F0
    ldr r3, [r3, #0x2E0]
    ldrh r2, [r1, #0x84]
    mov r0, #0x1C
    mla r0, r2, r0, r3
    ldrh r0, [r0, #0x16]
    cmp r0, #0
    bne loc_1F0
    ldrh r0, [r1, #0x8A]
    cmp r0, #0
    bne loc_1F0
    mov r0, #1
    bl fn_02396EFC
loc_1F0:
    add sp, sp, #4
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
}
