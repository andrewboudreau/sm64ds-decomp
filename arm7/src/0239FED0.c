/* Hand-asm: switch dispatch, cond-exec counter blocks and register allocation
   unreachable from C.
   Pool: 0x380FFF4, 0x4F4, 0x4EC. */
extern int *dat_0380FFF4;
extern void fn_0239AAA8(int);
extern void fn_0239A98C(int, int);
extern void fn_0239B76C(void *, int);
extern void fn_0239B5F4(void *, int, void *);
extern void fn_0239B504(void *, int, void *);
extern void fn_0239A7A4(int);
extern void fn_023969F4(int);
extern void fn_02396A98(void);
extern void fn_0239B7E8(void);
extern void fn_02394DF8(int, void *);
extern int fn_023A07BC(int);

asm void fn_0239FED0(unsigned short *a1, int a2)
{
    stmfd sp!, {r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #4
    mov r5, r0
    mov r4, r1
    ldr r0, =dat_0380FFF4
    ldr r1, [r0]
    ldr r0, =0x4F4
    add r2, r1, r0
    ldrh r1, [r5, #2]
    ldrh r0, [r5, #8]
    ands r0, r0, #2
    bne loc_C4
    ldr r0, [r2]
    add r0, r0, #1
    str r0, [r2]
    ldrh r0, [r5, #0x18]
    ands r0, r0, #1
    addne r3, r2, #0x14
    ldrne r0, [r3]
    addne r0, r0, #1
    strne r0, [r3]
    addeq r3, r2, #0x10
    ldreq r0, [r3]
    addeq r0, r0, #1
    streq r0, [r3]
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    add r3, r0, #0x400
    ldrh r3, [r3, #0xEA]
    mov r3, r3, asr r1
    ands r3, r3, #1
    beq loc_D4
    ldrh r3, [r5, #0x14]
    ands r3, r3, #0x2000
    bne loc_D4
    ldr r6, [r0, #0x2E0]
    mov r3, #0x1C
    mul r3, r1, r3
    ldrh r3, [r6, r3]
    cmp r3, #0x40
    bne loc_D4
    ldr r3, =0x4EC
    add r6, r0, r3
    ldrh r3, [r6]
    mov r0, #1
    mvn r0, r0, lsl r1
    and r0, r3, r0
    strh r0, [r6]
    b loc_D4
loc_C4:
    add r3, r2, #4
    ldr r0, [r3]
    add r0, r0, #1
    str r0, [r3]
loc_D4:
    ldrh r0, [r5, #0x14]
    mov r0, r0, lsl #0x11
    movs r0, r0, lsr #0x1F
    addne r3, r2, #0x18
    ldrne r0, [r3]
    addne r0, r0, #1
    strne r0, [r3]
    add r3, r2, #8
    ldr r2, [r3]
    ldrh r0, [r5, #0xC]
    mov r0, r0, lsl #8
    add r0, r2, r0, lsr #16
    str r0, [r3]
    ldrh r0, [r5, #0x14]
    and r6, r0, #0xFC
    cmp r6, #0x30
    bhi loc_140
    cmp r6, #0x30
    bhs loc_1F8
    cmp r6, #0x10
    bhi loc_138
    cmp r6, #0x10
    bhs loc_1F8
    cmp r6, #0
    b loc_45C
loc_138:
    cmp r6, #0x20
    b loc_45C
loc_140:
    cmp r6, #0xB0
    bhi loc_15C
    cmp r6, #0xB0
    bhs loc_168
    cmp r6, #0xA0
    beq loc_270
    b loc_45C
loc_15C:
    cmp r6, #0xC0
    beq loc_368
    b loc_45C
loc_168:
    ldrh r0, [r5, #8]
    ands r0, r0, #2
    bne loc_45C
    ldrh r2, [r5, #0x2C]
    cmp r2, #0
    bne loc_1B8
    ldrh r0, [r5, #0x2E]
    cmp r0, #2
    bne loc_1B8
    ldrh r0, [r5, #0x30]
    cmp r0, #0
    bne loc_1B8
    mov r0, r1, lsl #0x10
    mov r0, r0, lsr #0x10
    mov r1, #0x30
    bl fn_0239A98C
    add r0, r5, #0x18
    ldrh r1, [r5, #0x2C]
    bl fn_0239B76C
    b loc_45C
loc_1B8:
    cmp r2, #1
    bne loc_45C
    ldrh r0, [r5, #0x2E]
    cmp r0, #4
    bne loc_45C
    ldrh r0, [r5, #0x30]
    cmp r0, #0
    bne loc_45C
    mov r0, r1, lsl #0x10
    mov r0, r0, lsr #0x10
    mov r1, #0x30
    bl fn_0239A98C
    add r0, r5, #0x18
    ldrh r1, [r5, #0x2C]
    bl fn_0239B76C
    b loc_45C
loc_1F8:
    ldrh r0, [r5, #8]
    ands r0, r0, #2
    bne loc_260
    ldrh r0, [r5, #0x2E]
    cmp r0, #0
    bne loc_45C
    mov r0, r1, lsl #0x10
    mov r0, r0, lsr #0x10
    mov r1, #0x40
    bl fn_0239A98C
    cmp r6, #0x10
    bne loc_244
    add r0, r5, #0x18
    ldrh r1, [r5, #0x30]
    add r3, r5, #0x14
    ldrh r2, [r5, #0x12]
    add r2, r3, r2
    bl fn_0239B5F4
    b loc_45C
loc_244:
    add r0, r5, #0x18
    ldrh r1, [r5, #0x30]
    add r3, r5, #0x14
    ldrh r2, [r5, #0x12]
    add r2, r3, r2
    bl fn_0239B504
    b loc_45C
loc_260:
    mov r0, r1, lsl #0x10
    mov r0, r0, lsr #0x10
    bl fn_0239A7A4
    b loc_45C
loc_270:
    ldr r8, =dat_0380FFF4
    ldr r3, [r8]
    add r0, r3, #0x300
    ldrh r2, [r0, #0x14]
    cmp r2, #1
    bne loc_318
    cmp r1, #0
    beq loc_2BC
    ldr r2, [r3, #0x2E0]
    mov r0, #0x1C
    mul r0, r1, r0
    ldrh r0, [r2, r0]
    cmp r0, #0x30
    bls loc_330
    mov r0, r1, lsl #0x10
    mov r0, r0, lsr #0x10
    mov r1, #0x30
    bl fn_0239A98C
    b loc_330
loc_2BC:
    ldrh r0, [r5, #0x18]
    ands r0, r0, #1
    beq loc_330
    mov r9, #1
    mov r7, #0x30
    mov r6, #0x1C
    b loc_300
loc_2D8:
    ldr r1, [r1, #0x2E0]
    mul r0, r9, r6
    ldrh r0, [r1, r0]
    cmp r0, #0x30
    bls loc_2FC
    mov r0, r9, lsl #0x10
    mov r0, r0, lsr #0x10
    mov r1, r7
    bl fn_0239A98C
loc_2FC:
    add r9, r9, #1
loc_300:
    ldr r1, [r8]
    add r0, r1, #0x200
    ldrh r0, [r0, #0xE6]
    cmp r9, r0
    blo loc_2D8
    b loc_330
loc_318:
    ldrh r0, [r0, #0x10]
    cmp r0, #0x30
    bls loc_330
    mov r0, #0x30
    bl fn_023969F4
    bl fn_02396A98
loc_330:
    ldr r3, =dat_0380FFF4
    ldr r2, [r3]
    add r0, r2, #0x300
    ldrh r0, [r0, #0xBC]
    cmp r0, #0x71
    bne loc_45C
    mov r1, #0
    ldr r0, [r2, #0x3D8]
    strh r1, [r0, #4]
    ldr r0, [r3]
    add r0, r0, #0x300
    strh r1, [r0, #0xBC]
    bl fn_0239B7E8
    b loc_45C
loc_368:
    ldr r8, =dat_0380FFF4
    ldr r3, [r8]
    add r0, r3, #0x300
    ldrh r2, [r0, #0x14]
    cmp r2, #1
    bne loc_410
    cmp r1, #0
    beq loc_3B4
    ldr r2, [r3, #0x2E0]
    mov r0, #0x1C
    mul r0, r1, r0
    ldrh r0, [r2, r0]
    cmp r0, #0x20
    bls loc_428
    mov r0, r1, lsl #0x10
    mov r0, r0, lsr #0x10
    mov r1, #0x20
    bl fn_0239A98C
    b loc_428
loc_3B4:
    ldrh r0, [r5, #0x18]
    ands r0, r0, #1
    beq loc_428
    mov r9, #1
    mov r7, #0x20
    mov r6, #0x1C
    b loc_3F8
loc_3D0:
    ldr r1, [r1, #0x2E0]
    mul r0, r9, r6
    ldrh r0, [r1, r0]
    cmp r0, #0x20
    bls loc_3F4
    mov r0, r9, lsl #0x10
    mov r0, r0, lsr #0x10
    mov r1, r7
    bl fn_0239A98C
loc_3F4:
    add r9, r9, #1
loc_3F8:
    ldr r1, [r8]
    add r0, r1, #0x200
    ldrh r0, [r0, #0xE6]
    cmp r9, r0
    blo loc_3D0
    b loc_428
loc_410:
    ldrh r0, [r0, #0x10]
    cmp r0, #0x20
    bls loc_428
    mov r0, #0x20
    bl fn_023969F4
    bl fn_02396A98
loc_428:
    ldr r3, =dat_0380FFF4
    ldr r2, [r3]
    add r0, r2, #0x300
    ldrh r0, [r0, #0xBC]
    cmp r0, #0x41
    bne loc_45C
    mov r1, #0
    ldr r0, [r2, #0x3D8]
    strh r1, [r0, #4]
    ldr r0, [r3]
    add r0, r0, #0x300
    strh r1, [r0, #0xBC]
    bl fn_0239B7E8
loc_45C:
    mov r0, r5
    bl fn_0239AAA8
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    add r0, r0, #0x164
    sub r1, r5, #0x10
    bl fn_02394DF8
    mov r2, #0
    ldr r1, =dat_0380FFF4
    ldr r0, [r1]
    add r0, r0, #0x300
    strh r2, [r0, #0xF8]
    cmp r4, #0
    beq loc_4B0
    ldr r0, [r1]
    add r0, r0, #0x100
    ldrh r0, [r0, #0x6C]
    cmp r0, #0
    beq loc_4B0
    mov r0, #1
    bl fn_023A07BC
loc_4B0:
    add sp, sp, #4
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, lr}
    bx lr
}
