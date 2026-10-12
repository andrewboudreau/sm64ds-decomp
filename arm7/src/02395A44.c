/* Hand-asm: the ROM keeps the loop counter in ip while every C form mwcc
   emits parks it in r3 (the extra live value for the hi-half read demotes
   it). Pool +0x34: unk_27D65E4. */
extern unsigned short unk_27D65E4[];

asm int fn_02395A44(void)
{
    mov ip, #0
    ldr r2, =unk_27D65E4
loc_loop:
    mov r3, ip, lsl #2
    add r0, r2, ip, lsl #2
    ldrh r1, [r0, #2]
    ldrh r0, [r2, r3]
    add r0, r0, #0x4800000
    add r0, r0, #0x8000
    strh r1, [r0]
    add ip, ip, #1
    cmp ip, #0x16
    bcc loc_loop
    bx lr
}
