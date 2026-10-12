/* Hand-asm: `bx r2` indirect callback, loop-back control flow and cold islands
   unreachable from C.
   Pool: 0x380FFF4, 0x494, 0x3E6, 0x3FFF. */
extern int *dat_0380FFF4;
extern int fn_02380884(int);
extern int fn_023808C0(int);
extern int fn_02394B80(int);
extern void fn_0239D638(int, void *);
extern void fn_0239AAA8(int);
extern void fn_02396EFC(int);
extern int fn_023A05A4(int, int);

asm int fn_023A07BC(int a1)
{
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #4
    mov r10, r0
    mov r0, #0xC
    mul r4, r10, r0
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    add r0, r0, r4
    add r0, r0, #0x100
    ldrh r0, [r0, #0x60]
    cmp r0, #0
    beq loc_2BC
    mov r0, #0x1000000
    bl fn_02380884
    mov r11, r0
    mov r1, #0x14
    mul r5, r10, r1
    ldr r1, =dat_0380FFF4
    ldr r2, [r1]
    add r1, r2, r5
    add r1, r1, #0x300
    ldrh r1, [r1, #0xE4]
    cmp r1, #0
    beq loc_68
    bl fn_023808C0
    b loc_2BC
loc_68:
    add r0, r2, r4
    ldr r8, [r0, #0x158]
    mov r4, #2
    mov r0, #0
    str r0, [sp]
loc_7C:
    mvn r0, #0
    cmp r8, r0
    bne loc_94
    mov r0, r11
    bl fn_023808C0
    b loc_2BC
loc_94:
    mov r9, r8
    mov r0, r8
    bl fn_02394B80
    mov r8, r0
    add r7, r9, #0x10
    ldrh r6, [r7, #2]
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    ldr r2, [r0, #0x3A4]
    ldrh r1, [r7, #4]
    sub r1, r2, r1
    mov r1, r1, lsl #0x10
    mov r2, r1, lsr #0x10
    add r1, r0, #0x300
    ldrh r1, [r1, #0x88]
    cmp r2, r1
    bls loc_120
    add r1, r0, #0x3E4
    add r2, r1, r5
    ldr r1, =0x494
    add r1, r0, r1
    ldrh r0, [r1]
    add r0, r0, #1
    strh r0, [r1]
    strh r4, [r7, #8]
    add r1, r2, #4
    ldrh r0, [r1]
    add r0, r0, #1
    strh r0, [r1]
    mov r0, r7
    ldr r1, [sp]
    ldr r2, [r2, #0x10]
    mov lr, pc
    bx r2
    b loc_7C
loc_120:
    cmp r10, #0
    bne loc_178
    add r1, r0, #0x400
    ldrh r1, [r1, #0xEC]
    mov r1, r1, asr r6
    ands r1, r1, #1
    beq loc_7C
    ldr r2, [r0, #0x2E0]
    mov r1, #0x1C
    mul r1, r6, r1
    ldrh r1, [r2, r1]
    cmp r1, #0x40
    beq loc_178
    strh r4, [r7, #8]
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    add r0, r0, #0x158
    sub r1, r7, #0x10
    bl fn_0239D638
    mov r0, r7
    bl fn_0239AAA8
    b loc_7C
loc_178:
    mov r1, #1
    add r0, r0, r5
    add r0, r0, #0x300
    strh r1, [r0, #0xE4]
    ldr r1, =dat_0380FFF4
    ldr r0, [r1]
    add r2, r0, r5
    ldr r0, =0x3E6
    ldrh r0, [r2, r0]!
    add r0, r0, #1
    strh r0, [r2]
    ldr r0, [r1]
    add r0, r0, r5
    str r7, [r0, #0x3F0]
    ldr r1, [r1]
    add r0, r1, r5
    ldr r4, [r0, #0x3EC]
    add r0, r1, #0x300
    ldrh r0, [r0, #0x16]
    mov r0, r0, lsl #0x1E
    mov r0, r0, lsr #0x1F
    cmp r0, #1
    bne loc_1DC
    mov r0, #2
    bl fn_02396EFC
loc_1DC:
    mov r0, r4
    mov r1, r9
    bl fn_023A05A4
    ldr r0, =dat_0380FFF4
    ldr r1, [r0]
    add r0, r1, #0x300
    ldrh r0, [r0, #0x14]
    cmp r0, #1
    bne loc_224
    ldr r1, [r1, #0x2E0]
    mov r0, #0x1C
    mla r0, r6, r0, r1
    ldrh r0, [r0, #0x16]
    cmp r0, #1
    addhi r1, r4, #0xC
    ldrhih r0, [r1]
    orrhi r0, r0, #0x2000
    strhih r0, [r1]
loc_224:
    ldrh r1, [r7, #0x14]
    and r0, r1, #0xC
    cmp r0, #4
    bne loc_25C
    ldr r0, =0x3FFF
    and r0, r4, r0
    mov r0, r0, lsl #0xF
    mov r0, r0, lsr #0x10
    orr r1, r0, #0xA000
    mov r0, r10, lsl #2
    add r0, r0, #0x4800000
    add r0, r0, #0x8000
    strh r1, [r0, #0xA0]
    b loc_2B4
loc_25C:
    and r0, r1, #0xFC
    cmp r0, #0x50
    bne loc_290
    ldr r0, =0x3FFF
    and r0, r4, r0
    mov r0, r0, lsl #0xF
    mov r0, r0, lsr #0x10
    orr r1, r0, #0x9000
    mov r0, r10, lsl #2
    add r0, r0, #0x4800000
    add r0, r0, #0x8000
    strh r1, [r0, #0xA0]
    b loc_2B4
loc_290:
    ldr r0, =0x3FFF
    and r0, r4, r0
    mov r0, r0, lsl #0xF
    mov r0, r0, lsr #0x10
    orr r1, r0, #0x8000
    mov r0, r10, lsl #2
    add r0, r0, #0x4800000
    add r0, r0, #0x8000
    strh r1, [r0, #0xA0]
loc_2B4:
    mov r0, r11
    bl fn_023808C0
loc_2BC:
    add sp, sp, #4
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
}
