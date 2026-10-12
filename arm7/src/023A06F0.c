/* Hand-asm: r1/r2 scratch order in the +0x40C flag block unreachable from C.
   Pool: 0x380FFF4, 0x40E, 0x3FFF, 0x48080A8.
   Tail at +0x54 is the shared epilogue called by fn_023A07BC's cold block. */
extern int *dat_0380FFF4;
extern int fn_02380884(int);
extern int fn_023808C0(int);
extern int fn_023A05A4(int, int);

asm int fn_023A06F0(void)
{
    stmfd sp!, {r4, r5, r6, lr}
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    add r0, r0, #0x100
    ldrh r5, [r0, #0x78]
    cmp r5, #0
    beq loc_B4
    mov r0, #0x1000000
    bl fn_02380884
    mov r4, r0
    ldr r3, =dat_0380FFF4
    ldr r1, [r3]
    add r1, r1, #0x400
    ldrh r2, [r1, #0xC]
    cmp r2, #0
    beq loc_48
    bl fn_023808C0
    b loc_B4
loc_48:
    mov r0, #1
    strh r0, [r1, #0xC]
    ldr r1, [r3]
    ldr r0, =0x40E
    ldrh r0, [r1, r0]!
    add r0, r0, #1
    strh r0, [r1]
    ldr r2, [r3]
    ldr r1, [r2, #0x170]
    ldr r6, [r2, #0x414]
    add r0, r1, #0x10
    str r0, [r2, #0x418]
    mov r0, r6
    bl fn_023A05A4
    cmp r5, #1
    addhi r1, r6, #0xC
    ldrhih r0, [r1]
    orrhi r0, r0, #0x2000
    strhih r0, [r1]
    ldr r0, =0x3FFF
    and r0, r6, r0
    mov r0, r0, lsr #1
    orr r1, r0, #0x8000
    ldr r0, =0x48080A8
    strh r1, [r0]
    mov r0, r4
    bl fn_023808C0
loc_B4:
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
}
