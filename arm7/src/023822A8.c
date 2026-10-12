/* storage 0x023822A8 runtime 0x037FA140 size 0x74 wram ARM.
 * Queue-entry rearm: if the node pointer is null or still armed, reset it,
 * take the lock, clear timer words, stamp new ids, add the 64-bit timebase
 * to the (a3,a2) pair, release the lock. Five calls, no pools.
 * Whole-asm: the tail parks lo in R2 and sets up arg0 before the ADDS
 * (MOV R2,R0; MOV R0,R7; ADDS R3,R6,R2; ADC R2,R5,R1; MOV R1,R3).
 * Thirty C and C+asm tail spellings were measured (see job report): pure C
 * carries cost CMP+MOVcc (+2..4 words); u64 arithmetic will not fuse
 * (MOV#0+ADDS+ADC chains); inline-asm ADDS+ADC with C operands is correct
 * but one word short with rotated homes (0x70, a1 in R6, no park), and any
 * fifth tail local miscompiles (R5 used undefined). b56 has no C-level way
 * to park a return half in a scratch reg ahead of arg setup, so the
 * function is hand-assembled like 02380CEC. */

extern void fn_02382B38(void); /* =0x037FA9D0 */
extern int fn_02382AC4(void); /* =0x037FA95C */
extern unsigned long long fn_023821B0(void); /* =0x037F9D48 */
extern void fn_0238231C(int *, int, int); /* =0x037FA1B4 */
extern int fn_02382AD8(int); /* =0x037FA970 */

asm int fn_023822A8(int *a1, unsigned int a2, unsigned int a3, int a4, int a5) {
    STMDB SP!, {R4-R8, LR}
    MOVS R7, R0
    MOV R6, R1
    MOV R5, R2
    MOV R8, R3
    BEQ do_reset
    LDR R0, [R7]
    CMP R0, #0
    BEQ no_reset
do_reset:
    BL fn_02382B38
no_reset:
    BL fn_02382AC4
    MOV R4, R0
    MOV R0, #0
    STR R0, [R7, #0x1C]
    STR R0, [R7, #0x20]
    STR R8, [R7]
    LDR R0, [SP, #0x18]
    STR R0, [R7, #4]
    BL fn_023821B0
    MOV R2, R0
    MOV R0, R7
    ADDS R3, R6, R2
    ADC R2, R5, R1
    MOV R1, R3
    BL fn_0238231C
    MOV R0, R4
    BL fn_02382AD8
    LDMIA SP!, {R4-R8, LR}
    BX LR
}
