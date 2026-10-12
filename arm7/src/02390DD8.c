/* Hand-asm: nested dispatch handler; the status-test/branch schedule is not
   reachable from mwccarm C. Pool +0x310: 0x303, 0xFFFF. */
extern int fn_0238E688(void);
extern unsigned short *fn_0238DE4C(void);
extern int fn_0238DEF4(unsigned short *);
extern unsigned short *fn_0238FB00(void *);
extern int fn_02390D9C(int, int);
extern int fn_0238E2CC(int, void *);
extern unsigned short *fn_0238FB70(void *);
extern unsigned short *fn_0239045C(void *, int, int, int);
extern void fn_02382C80(int, void *, int);
extern void fn_02382D2C(void *, int, int);
extern unsigned short *fn_023903A0(void *, int, void *, int, void *, int, void *, int);
extern void fn_02382DC0(void *, void *, unsigned int);
extern int fn_0238E184(int);
extern int fn_0238E0BC(int);
extern void fn_0238E57C(void *, void *);
extern void fn_02382C98(void *, void *, int);

asm int fn_02390DD8(int *a1)
{
    stmfd sp!, {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #0x250
    mov r8, r0
    add r5, sp, #0x4C
    bl fn_0238E688
    add r0, r0, #0x1000
    ldr r7, [r0, #0x610]
    ldr r1, [r8, #4]
    ldr r0, [r7]
    str r1, [r0, #0x180]
    ldrh r6, [r8, #2]
    ldr r0, [r7]
    add r0, r0, #0x100
    strh r6, [r0, #0x8C]
    ldrh r4, [r8, #8]
    ldrh r0, [r8, #0xA]
    strh r0, [sp, #0x16]
    ldrh r0, [r8, #0xC]
    strh r0, [sp, #0x18]
    ldrh r0, [r8, #0xE]
    strh r0, [sp, #0x1A]
    cmp r6, #0
    bne l74
    bl fn_0238DE4C
    mov r1, #0xA
    strh r1, [r0]
    mov r1, #6
    strh r1, [r0, #2]
    bl fn_0238DEF4
l74:
    ldr r2, [r7]
    mov r0, #1
    mov r1, r0, lsl r6
    add r0, r2, #0x100
    ldrh r0, [r0, #0xF0]
    ands r0, r1, r0
    bne lac
    bl fn_0238DE4C
    mov r1, #0xA
    strh r1, [r0]
    mov r1, #6
    strh r1, [r0, #2]
    bl fn_0238DEF4
    b l304
lac:
    mov r0, #2
    strh r0, [r2, #0xE2]
    mov r0, r5
    bl fn_0238FB00
    ldrh r1, [r0, #4]
    cmp r1, #0
    beq ld4
    mov r0, #0x308
    bl fn_02390D9C
    b l304
ld4:
    ldrh r0, [r0, #6]
    cmp r0, #0x10
    bne l14c
    mov r0, #0xA
    mov r1, r5
    bl fn_0238E2CC
    cmp r0, #0
    beq l304
    mov r0, r5
    bl fn_0238FB70
    ldrh r1, [r0, #4]
    cmp r1, #0
    beq l114
    ldr r0, =0x303
    bl fn_02390D9C
    b l304
l114:
    mov r1, #3
    ldr r0, [r7]
    strh r1, [r0]
    mov r0, r5
    mov r1, #1
    mov r2, #0
    mov r3, r1
    bl fn_0239045C
    ldrh r1, [r0, #4]
    cmp r1, #0
    beq l14c
    mov r0, #1
    bl fn_02390D9C
    b l304
l14c:
    mov r1, #5
    ldr r0, [r7]
    strh r1, [r0]
    ldr r0, =0xFFFF
    strh r0, [sp, #0x10]
    ldrh r0, [sp, #0x10]
    add r1, sp, #0x1C
    mov r2, #0x20
    bl fn_02382C80
    strb r6, [sp, #0x3C]
    add r0, sp, #0x3D
    mov r1, #0
    mov r2, #0xF
    bl fn_02382D2C
    add r0, sp, #0x1C
    str r0, [sp]
    mov r0, #1
    str r0, [sp, #4]
    add r0, sp, #0x3C
    str r0, [sp, #8]
    str r4, [sp, #0xC]
    mov r0, r5
    mov r1, #0x11C
    add r2, sp, #0x16
    mov r3, #0
    bl fn_023903A0
    mov r4, r0
    ldrh r1, [r4, #4]
    cmp r1, #0
    beq l1d0
    mov r0, #2
    bl fn_02390D9C
    b l304
l1d0:
    bl fn_0238DE4C
    mov r5, r0
    ldrh r0, [r4, #8]
    cmp r0, #0
    bne l208
    mov r0, #0xA
    strh r0, [r5]
    mov r1, #0
    strh r1, [r5, #2]
    mov r0, #4
    strh r0, [r5, #8]
    strh r6, [r5, #0x10]
    strh r1, [r5, #0x12]
    b l2fc
l208:
    mov r0, #0
    strh r0, [sp, #0x12]
    ldrh r0, [sp, #0x12]
    ldr r1, [r7]
    ldr r1, [r1, #0x180]
    add r1, r1, #0x40
    mov r2, #0x80
    bl fn_02382C80
    add r0, r4, #0xA
    ldr r1, [r7]
    ldr r1, [r1, #0x180]
    mov r2, #0xC0
    bl fn_02382DC0
    mov r0, #0xA
    strh r0, [r5]
    mov r0, #0
    strh r0, [r5, #2]
    mov r0, #5
    strh r0, [r5, #8]
    ldrh r0, [r4, #0x40]
    strh r0, [r5, #0x10]
    ldrh r0, [r4, #0xC]
    and r0, r0, #0xFF
    bl fn_0238E184
    bl fn_0238E0BC
    strh r0, [r5, #0x12]
    ldrh r0, [r4, #0x14]
    strh r0, [r5, #0x14]
    add r0, r5, #0xA
    add r1, r4, #0xE
    bl fn_0238E57C
    add r0, r4, #0x16
    add r1, r5, #0x16
    mov r2, #0x20
    bl fn_02382C98
    ldrh r0, [r4, #0x46]
    strh r0, [r5, #0x36]
    ldrh r0, [r5, #0x36]
    cmp r0, #0x80
    bls l2cc
    mov r0, #0xA
    strh r0, [r5]
    mov r1, #0
    strh r1, [r5, #2]
    mov r0, #4
    strh r0, [r5, #8]
    strh r6, [r5, #0x10]
    strh r1, [r5, #0x12]
    b l2fc
l2cc:
    mov r0, #0
    strh r0, [sp, #0x14]
    ldrh r0, [sp, #0x14]
    add r1, r5, #0x38
    mov r2, #0x80
    bl fn_02382C80
    add r0, r4, #0x4A
    add r1, r5, #0x38
    ldrh r2, [r5, #0x36]
    add r2, r2, #1
    bic r2, r2, #1
    bl fn_02382C98
l2fc:
    mov r0, r5
    bl fn_0238DEF4
l304:
    add sp, sp, #0x250
    ldmfd sp!, {r4, r5, r6, r7, r8, lr}
    bx lr
}
