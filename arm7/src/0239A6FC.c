/* Hand-asm: matches only under -O4,p from C (the -O4,s scheduler inserts a
   mov before the orr'd call-result). Pool: 0x380FFF4, 0x480425C. */
extern int *dat_0380FFF4;
extern int fn_02380884(int);
extern int fn_023808C0(int);
extern int fn_02395334(void *);
extern int fn_02395354(void *, int);

asm int fn_0239A6FC(int a1)
{
    stmfd sp!, {r4, r5, r6, lr}
    mov r6, r0
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    add r0, r0, #0x300
    ldrh r1, [r0, #0x90]
    ldr r0, =0x480425C
    add r5, r1, r0
    mov r0, #0x1000000
    bl fn_02380884
    mov r4, r0
    cmp r6, #0
    bne loc_6C4
    add r0, r5, #4
    bl fn_02395334
    orr r1, r0, #1
    add r0, r5, #4
    and r1, r1, #0xFF
    bl fn_02395354
    b loc_704
loc_6C4:
    ldr r0, =dat_0380FFF4
    ldr r0, [r0]
    ldr r1, [r0, #0x2E0]
    mov r0, #0x1C
    mla r0, r6, r0, r1
    ldrh r6, [r0, #2]
    add r0, r5, #5
    add r5, r0, r6, lsr #3
    mov r0, r5
    bl fn_02395334
    mov r2, #1
    and r1, r6, #7
    orr r1, r0, r2, lsl r1
    mov r0, r5
    and r1, r1, #0xFF
    bl fn_02395354
loc_704:
    mov r0, r4
    bl fn_023808C0
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
}
