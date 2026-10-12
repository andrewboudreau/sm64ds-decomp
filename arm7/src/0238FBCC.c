/* Hand-asm: tail call through a pooled pointer (BX R12). With six args the
   callee's stack args must be forwarded in place; mwcc rebuilds the frame
   instead. Pools +0x10/+0x14: literal 0x283, fn_0238FA3C. */
extern int fn_0238FA3C(short *, int, int, int, int, int);

asm int fn_0238FBCC(short *a1, int a2, int a3, int a4, int a5, int a6)
{
    ldr r1, =0x283
    mov r2, #3
    ldr ip, =fn_0238FA3C
    bx ip
}
