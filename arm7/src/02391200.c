/* Hand-asm: large state dispatch with conditional-instruction field writes;
   not reachable from mwccarm C. Pool +0x450: 0x1FFF, 0x303, 0x186. */
extern int fn_0238E688(void);
extern void fn_02382DC0(void *, void *, unsigned int);
extern unsigned short *fn_0238DE4C(void);
extern int fn_0238DEF4(unsigned short *);
extern int fn_0238E2CC(int, void *);
extern unsigned short *fn_0238FB70(void *);
extern int fn_023911C4(int, int);
extern unsigned short *fn_0239031C(void *, int, void *);
extern void fn_0238E57C(void *, void *);
extern unsigned short *fn_02390298(void *, void *, int, int);
extern unsigned short *fn_02390194(void *, void *, int, int);
extern void fn_02382C80(int, void *, int);
extern int fn_02393CA8(void);
extern int fn_0238E184(int);
extern int fn_0238E0BC(int);
extern int fn_0238E120(int);

asm int fn_02391200(int *a1)
{
    stmfd sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x258
    mov r6, r0
    add r5, sp, #0x10
    bl fn_0238E688
    add r0, r0, #0x1000
    ldr r4, [r0, #0x610]
    ldr r0, [r6, #4]
    add r1, r4, #0x10
    mov r2, #0xC0
    bl fn_02382DC0
    ldrh r0, [r4, #0x4C]
    cmp r0, #0x10
    bcc l68
    ldrb r0, [r4, #0x5B]
    ands r0, r0, #1
    bne l68
    bl fn_0238DE4C
    mov r1, #0xC
    strh r1, [r0]
    mov r1, #0xB
    strh r1, [r0, #2]
    mov r1, #6
    strh r1, [r0, #8]
    bl fn_0238DEF4
    b l444
l68:
    mov r1, #1
    ldrh r0, [r4, #0x46]
    mov r1, r1, lsl r0
    ldr r0, [r4]
    add r0, r0, #0x100
    ldrh r0, [r0, #0xF0]
    ands r0, r1, r0
    beq l98
    mov r1, r1, asr #1
    ldr r0, =0x1FFF
    ands r0, r1, r0
    bne lb8
l98:
    bl fn_0238DE4C
    mov r1, #0xC
    strh r1, [r0]
    mov r1, #6
    strh r1, [r0, #2]
    strh r1, [r0, #8]
    bl fn_0238DEF4
    b l444
lb8:
    bl fn_0238DE4C
    mov r1, #0xC
    strh r1, [r0]
    mov r1, #0
    strh r1, [r0, #2]
    mov r1, #6
    strh r1, [r0, #8]
    bl fn_0238DEF4
    ldr r0, [r4]
    add r0, r0, #0x100
    ldrh r1, [r0, #0xE8]
    cmp r1, #1
    bne l108
    ldrh r1, [r4, #0x3E]
    ands r1, r1, #1
    movne r1, #1
    strneh r1, [r0, #0xE8]
    moveq r1, #2
    streqh r1, [r0, #0xE8]
    b l120
l108:
    ldrh r1, [r4, #0x3E]
    ands r1, r1, #2
    movne r1, #2
    strneh r1, [r0, #0xE8]
    moveq r1, #1
    streqh r1, [r0, #0xE8]
l120:
    ldrh r0, [r4, #0x3C]
    ands r0, r0, #0x20
    movne r1, #1
    ldrne r0, [r4]
    addne r0, r0, #0x100
    strneh r1, [r0, #0xEA]
    moveq r1, #0
    ldreq r0, [r4]
    addeq r0, r0, #0x100
    streqh r1, [r0, #0xEA]
    ldrh r0, [r4, #0x3C]
    ands r0, r0, #0x10
    movne r1, #1
    ldrne r0, [r4]
    strne r1, [r0, #0x194]
    moveq r1, #0
    ldreq r0, [r4]
    streq r1, [r0, #0x194]
    ldrh r0, [r4, #0x4C]
    cmp r0, #0
    moveq r1, #3
    ldreq r0, [r4]
    streqh r1, [r0, #0xE2]
    movne r1, #2
    ldrne r0, [r4]
    strneh r1, [r0, #0xE2]
    mov r0, #0xC
    mov r1, r5
    bl fn_0238E2CC
    cmp r0, #0
    beq l444
    mov r0, r5
    bl fn_0238FB70
    ldrh r1, [r0, #4]
    cmp r1, #0
    beq l1bc
    ldr r0, =0x303
    bl fn_023911C4
    b l444
l1bc:
    add r0, r4, #0x10
    add r1, sp, #0x210
    mov r2, #0x40
    bl fn_02382DC0
    ldr r0, [r4]
    ldrh r0, [r0, #0xE2]
    cmp r0, #2
    bne l218
    mov r1, #0x20
    add r0, sp, #0x200
    strh r1, [r0, #0x1A]
    ldrh r1, [r4, #0x54]
    strh r1, [r0, #0x1C]
    ldrh r1, [r4, #0x56]
    strh r1, [r0, #0x1E]
    ldrh r1, [r4, #0x58]
    strh r1, [r0, #0x20]
    mov r1, #0
    strh r1, [r0, #0x22]
    add r0, r6, #8
    add r1, sp, #0x224
    mov r2, #0x18
    bl fn_02382DC0
l218:
    mov r0, r5
    mov r1, #0x7D0
    add r2, sp, #0x210
    bl fn_0239031C
    mov r2, r0
    ldrh r1, [r2, #4]
    cmp r1, #0
    bne l244
    ldrh r0, [r2, #6]
    cmp r0, #0
    beq l250
l244:
    mov r0, #3
    bl fn_023911C4
    b l444
l250:
    ldr r1, [r4]
    ldr r0, =0x186
    add r0, r1, r0
    add r1, r2, #8
    bl fn_0238E57C
    ldrb r0, [r4, #0x5B]
    ands r0, r0, #4
    movne r1, #6
    moveq r1, #0
    ldrh r0, [r4, #0x5E]
    add r0, r0, #2
    add r1, r0, r1
    ldr r0, [r4]
    add r0, r0, #0x100
    strh r1, [r0, #0x8E]
    ldrb r0, [r4, #0x5B]
    ands r0, r0, #4
    movne r1, #0x2A
    moveq r1, #0
    ldrh r0, [r4, #0x5C]
    add r0, r0, #4
    add r1, r0, r1
    ldr r0, [r4]
    add r0, r0, #0x100
    strh r1, [r0, #0x90]
    add r0, sp, #2
    ldr r2, [r4]
    ldr r1, =0x186
    add r1, r2, r1
    bl fn_0238E57C
    mov r0, r5
    add r1, sp, #2
    mov r2, #0
    mov r3, #0x7D0
    bl fn_02390298
    ldrh r1, [r0, #4]
    cmp r1, #0xC
    bne l30c
    ldrh r2, [r0, #6]
    cmp r2, #0x13
    bne l30c
    bl fn_0238DE4C
    mov r1, #0xC
    strh r1, [r0]
    strh r1, [r0, #2]
    bl fn_0238DEF4
    b l444
l30c:
    cmp r1, #0
    bne l320
    ldrh r0, [r0, #6]
    cmp r0, #0
    beq l32c
l320:
    mov r0, #4
    bl fn_023911C4
    b l444
l32c:
    add r0, sp, #8
    ldr r2, [r4]
    ldr r1, =0x186
    add r1, r2, r1
    bl fn_0238E57C
    mov r0, r5
    add r1, sp, #8
    mov r2, #1
    mov r3, #0x7D0
    bl fn_02390194
    ldrh r1, [r0, #4]
    cmp r1, #0xC
    bne l388
    ldrh r2, [r0, #6]
    cmp r2, #0x13
    bne l388
    bl fn_0238DE4C
    mov r1, #0xC
    strh r1, [r0]
    mov r1, #0xB
    strh r1, [r0, #2]
    bl fn_0238DEF4
    b l444
l388:
    cmp r1, #0
    bne l39c
    ldrh r2, [r0, #6]
    cmp r2, #0
    beq l3a8
l39c:
    mov r0, #6
    bl fn_023911C4
    b l444
l3a8:
    ldrh r1, [r0, #8]
    ldr r0, [r4]
    add r0, r0, #0x100
    strh r1, [r0, #0x84]
    ldrh r1, [r4, #0x58]
    ldr r0, [r4]
    strh r1, [r0, #0xB6]
    mov r0, #1
    strh r0, [sp]
    ldrh r0, [sp]
    ldr r1, [r4]
    add r1, r1, #0x1F4
    mov r2, #0x20
    bl fn_02382C80
    bl fn_02393CA8
    ldrh r0, [r4, #0x12]
    and r0, r0, #0xFF
    bl fn_0238E184
    mov r5, r0
    bl fn_0238E0BC
    ldr r1, [r4]
    strh r0, [r1, #0xB8]
    mov r0, r5
    bl fn_0238E120
    mov r1, #8
    ldr r0, [r4]
    strh r1, [r0]
    bl fn_0238DE4C
    mov r1, #0xC
    strh r1, [r0]
    mov r1, #0
    strh r1, [r0, #2]
    mov r1, #7
    strh r1, [r0, #8]
    ldr r1, [r4]
    add r1, r1, #0x100
    ldrh r1, [r1, #0x84]
    strh r1, [r0, #0xA]
    bl fn_0238DEF4
l444:
    add sp, sp, #0x258
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
}
