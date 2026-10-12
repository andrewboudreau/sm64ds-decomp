/* storage 0x0238C1C8 runtime 0x03804060 size 0xAC wram ARM.
 * 78-halfword compare with two precomputed XOR masks.
 * Whole-asm: six C shapes measured (see job report). V5/V6 are size-exact
 * 0xAC with the frame, emission order and branch structure identical, but
 * b56 homes temporaries differently in 8 words (exp/v2 R4<->R6, ffff/index
 * R0<->R1 class, EOR scratch R3 vs R2, m3 R1 vs LR, v5 LR vs R12, scaled
 * index ip vs R3). The (ffff R0, index R1) pair is the root: with index in
 * R0, R1 sits free at mask time so m3 parks low; only index-in-R1 forces
 * the ROM's scratch-R2/park-high shape, and no init/decl/unsigned/scratch-
 * temp permutation puts index in R1. Pre-UAL mnemonics throughout. */

extern int fn_0238104C(void); /* =0x037F88E4 */
extern void fn_02381174(int); /* =0x037F8A0C */
extern void fn_02381040(int); /* =0x037F88D8 */
extern void fn_023810E4(int); /* =0x037F897C */

asm int fn_0238C1C8(int a1) {
    STMDB SP!, {R4-R8, LR}
    MOV R7, R0
    MOV R0, #0x8000000
    ADD R6, R0, #4
    MOV R4, #1
    BL fn_0238104C
    MOV R0, R0, LSL #16
    MOV R5, R0, LSR #16
    MOV R0, R5
    BL fn_02381174
    MOV R1, #0
    LDR R0, =0xFFFF
    EOR R2, R0, #3
    MOV R2, R2, LSL #16
    MOV LR, R2, LSR #16
    EOR R2, R0, #0x84
    MOV R2, R2, LSL #16
    MOV R8, R2, LSR #16
    B L_check
L_head:
    MOV R12, R0
    CMP R1, #0x4C
    MOVEQ R12, R8
    BEQ L_body
    CMP R1, #0x4D
    MOVEQ R12, LR
L_body:
    MOV R3, R1, LSL #1
    LDRH R2, [R7, R3]
    AND R12, R12, R2
    LDRH R2, [R6, R3]
    CMP R12, R2
    MOVNE R4, #0
    BNE L_exit
    ADD R1, R1, #1
L_check:
    CMP R1, #0x4E
    BLT L_head
L_exit:
    MOV R0, R5
    BL fn_02381040
    MOV R0, R5
    BL fn_023810E4
    MOV R0, R4
    LDMIA SP!, {R4-R8, LR}
    BX LR
}
