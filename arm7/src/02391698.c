/* Hand-asm: state dispatch + per-flag loop with a pre-indexed halfword RMW
   ([r2,r1]!) and a two-entry packet loop; the schedule is not reachable from
   mwccarm C. Pool +0x304: 0x186, 0x302, 0x17E. */
extern int fn_0238E688(void);
extern void fn_0238E57C(void *, void *);
extern unsigned short *fn_02390214(void *, void *, int);
extern int fn_0239165C(int, int);
extern unsigned short *fn_023904C0(void *, int);
extern unsigned short *fn_0238FB88(void *);
extern unsigned short *fn_0238DE4C(void);
extern int fn_0238DEF4(unsigned short *);

asm int fn_02391698(int *a1, int a2)
{
    stmfd sp!, {r4-r11, lr}
    sub sp, sp, #0x21C
    mov r4, r0
    mov r8, r1
    bl fn_0238E688
    add r0, r0, #0x1000
    ldr r7, [r0, #0x610]
    ldr r0, [r4, #4]
    mov r0, r0, lsl #16
    mov r6, r0, lsr #16
    ldr r2, [r7]
    ldrh r0, [r2]
    cmp r0, #9
    beq l7c
    cmp r0, #7
    beq l7c
    cmp r0, #0xA
    beq l50
    cmp r0, #8
    bne l74
l50:
    cmp r0, #0xA
    bne l7c
    mov r1, #0
    str r1, [r2, #0x10]
    ldr r0, [r7]
    str r1, [r0, #0x18]
    ldr r0, [r7]
    str r1, [r0, #0x24]
    b l7c
l74:
    mov r0, #0
    b l2f8
l7c:
    ldr r2, [r7]
    ldrh r0, [r2]
    cmp r0, #0xA
    beq l94
    cmp r0, #8
    bne l1ac
l94:
    add r0, sp, #0x10
    ldr r1, =0x186
    add r1, r2, r1
    bl fn_0238E57C
    add r0, sp, #0x1C
    add r1, sp, #0x10
    mov r2, #3
    bl fn_02390214
    ldrh r1, [r0, #4]
    cmp r1, #0
    beq ld0
    mov r0, #5
    bl fn_0239165C
    mov r0, #0
    b l2f8
ld0:
    add r0, sp, #0x1C
    mov r1, #1
    bl fn_023904C0
    ldrh r1, [r0, #4]
    cmp r1, #0
    beq lf8
    mov r0, #0
    bl fn_0239165C
    mov r0, #0
    b l2f8
lf8:
    mov r1, #3
    ldr r0, [r7]
    strh r1, [r0]
    add r0, sp, #0x1C
    bl fn_0238FB88
    ldrh r1, [r0, #4]
    cmp r1, #0
    beq l128
    ldr r0, =0x302
    bl fn_0239165C
    mov r0, #0
    b l2f8
l128:
    mov r1, #2
    ldr r0, [r7]
    strh r1, [r0]
    mov r1, #0
    ldr r0, [r7]
    str r1, [r0, #0x10]
    ldr r0, [r7]
    str r1, [r0, #0x18]
    ldr r0, [r7]
    str r1, [r0, #0x14]
    cmp r8, #1
    bne l2f4
    bl fn_0238DE4C
    mov r1, #0xC
    strh r1, [r0]
    mov r2, #0
    strh r2, [r0, #2]
    mov r1, #9
    strh r1, [r0, #8]
    mov r1, #0x24
    strh r1, [r0, #0xC]
    ldr r1, [r7]
    add r1, r1, #0x100
    ldrh r1, [r1, #0x84]
    strh r1, [r0, #0xA]
    ldr r1, [r7]
    add r1, r1, #0x100
    strh r2, [r1, #0x8E]
    ldr r1, [r7]
    add r1, r1, #0x100
    strh r2, [r1, #0x90]
    bl fn_0238DEF4
    b l2f4
l1ac:
    mov r5, #1
    mov r0, #3
    str r0, [sp, #4]
    mov r11, #8
    mov r10, #0
    mov r0, #9
    str r0, [sp, #8]
    mov r0, #0x24
    str r0, [sp, #0xC]
    str r5, [sp]
    b l2ec
l1d8:
    ldr r1, [r7]
    ldr r0, [sp]
    mov r9, r0, lsl r5
    add r0, r1, #0x100
    ldrh r0, [r0, #0x7E]
    and r0, r0, r6
    ands r0, r9, r0
    beq l2e8
    mov r0, r5, lsl #16
    mov r4, r0, lsr #16
    add r0, sp, #0x16
    add r3, r1, #0x124
    sub r2, r5, #1
    mov r1, #6
    mla r1, r2, r1, r3
    bl fn_0238E57C
    add r0, sp, #0x1C
    add r1, sp, #0x16
    ldr r2, [sp, #4]
    bl fn_02390214
    ldrh r1, [r0, #4]
    cmp r1, #0
    beq l244
    mov r0, #5
    bl fn_0239165C
    mov r0, #0
    b l2f8
l244:
    mvn r0, r9
    ldr r2, [r7]
    ldr r1, =0x17E
    ldrh r1, [r2, r1]!
    and r1, r1, r0
    strh r1, [r2]
    ldr r1, [r7]
    add r2, r1, #0x86
    ldrh r1, [r2]
    and r0, r1, r0
    strh r0, [r2]
    mov r0, #6
    mul r0, r5, r0
    ldr r1, [r7]
    add r1, r1, r0
    add r1, r1, #0x100
    strh r10, [r1, #0x1E]
    ldr r1, [r7]
    add r1, r1, r0
    add r1, r1, #0x100
    strh r10, [r1, #0x20]
    ldr r1, [r7]
    add r0, r1, r0
    add r0, r0, #0x100
    strh r10, [r0, #0x22]
    cmp r8, #1
    bne l2e8
    bl fn_0238DE4C
    mov r9, r0
    strh r11, [r9]
    strh r10, [r9, #2]
    ldr r0, [sp, #8]
    strh r0, [r9, #8]
    ldr r0, [sp, #0xC]
    strh r0, [r9, #0x12]
    strh r4, [r9, #0x10]
    add r0, r9, #0xA
    add r1, sp, #0x16
    bl fn_0238E57C
    mov r0, r9
    bl fn_0238DEF4
l2e8:
    add r5, r5, #1
l2ec:
    cmp r5, #0x10
    blt l1d8
l2f4:
    mov r0, #1
l2f8:
    add sp, sp, #0x21C
    ldmfd sp!, {r4-r11, lr}
    bx lr
}
