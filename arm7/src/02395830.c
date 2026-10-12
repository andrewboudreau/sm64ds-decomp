/* Hand-asm: the middle block's register allocation is unreachable from C —
   the ROM parks &dat_0380FFF4 in r2 while every C form puts it in r1 (and
   v5 in r7 rather than r8), rotating the whole else-path allocation.
   Pool +0x1A0: unk_27D6574, dat_0380FFF4, 0x4808184, 0x5B8. */
extern int *dat_0380FFF4;
extern int fn_023A4340(int, int, void *);
extern int fn_0238D594(int, int);
extern int fn_02395B9C(int);
extern unsigned short unk_27D6574[];

asm int fn_02395830(void)
{
    stmfd sp!, {r4, r5, r6, r7, r8, sb, lr}
    sub sp, sp, #0xC
    mov r6, #0
    str r6, [sp, #4]
    mov r5, #2
    add r4, sp, #4
    ldr r7, =unk_27D6574
loc_1C:
    mov r0, r6, lsl #1
    add r0, r0, #0x44
    mov r1, r5
    mov r2, r4
    bl fn_023A4340
    ldr r1, [sp, #4]
    mov r0, r6, lsl #1
    ldrh r0, [r7, r0]
    add r0, r0, #0x4800000
    add r0, r0, #0x8000
    strh r1, [r0]
    add r6, r6, #1
    cmp r6, #0x10
    bcc loc_1C
    ldr r2, =dat_0380FFF4
    ldr r0, [r2]
    add r0, r0, #0x500
    ldrh r0, [r0, #0xB2]
    mov r1, r0, lsr #7
    mov r0, r1, lsl #8
    str r0, [sp]
    ldr r0, [r2]
    add r0, r0, #0x500
    ldrh r0, [r0, #0xB2]
    and r0, r0, #0x7F
    orr r1, r0, r1, lsl #8
    str r1, [sp]
    ldr r0, =0x4808184
    strh r1, [r0]
    mov r5, #0xCE
    ldr r6, [r2]
    add r0, r6, #0x500
    ldrh r0, [r0, #0xB2]
    and r0, r0, #0x7F
    add r0, r0, #7
    mov r1, #8
    bl fn_0238D594
    mov r8, r0
    add r0, r6, #0x500
    ldrh r4, [r0, #0xB4]
    ldrh r0, [r0, #0xB0]
    cmp r0, #3
    bne loc_130
    add r0, r4, #0xCE
    mov r1, #1
    ldr r2, =0x5B8
    add r2, r6, r2
    bl fn_023A4340
    mov sb, #0
    mov r8, sb
    mov r7, #1
    add r6, sp, #0
    b loc_124
loc_F0:
    str r8, [sp]
    mov r0, r5
    mov r1, r7
    mov r2, r6
    bl fn_023A4340
    ldr r1, [sp]
    mov r0, sb, lsl #8
    add r0, r0, #0x50000
    orr r0, r1, r0
    str r0, [sp]
    bl fn_02395B9C
    add sb, sb, #1
    add r5, r5, #1
loc_124:
    cmp sb, r4
    bcc loc_F0
    b loc_194
loc_130:
    mov r0, #0
    str r0, [sp]
    add r7, sp, #0
    ldr r6, =dat_0380FFF4
    b loc_18C
loc_144:
    mov r0, r5
    mov r1, r8
    mov r2, r7
    bl fn_023A4340
    ldr r0, [sp]
    bl fn_02395B9C
    ldr r2, [r6]
    add r0, r2, #0x500
    ldrh r0, [r0, #0xB0]
    cmp r0, #2
    bne loc_184
    ldr r1, [sp]
    mov r0, r1, lsr #18
    cmp r0, #9
    biceq r0, r1, #0x7C00
    streq r0, [r2, #0x5BC]
loc_184:
    sub r4, r4, #1
    add r5, r5, r8
loc_18C:
    cmp r4, #0
    bne loc_144
loc_194:
    add sp, sp, #0xC
    ldmfd sp!, {r4, r5, r6, r7, r8, sb, lr}
    bx lr
}
