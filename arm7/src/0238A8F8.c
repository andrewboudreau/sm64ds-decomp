/* storage 0x0238A8F8 runtime 0x03802790 size 0x128 wram ARM.
 * Channel mode switch. Whole-asm: b56 homes the saved field in R2 and the
 * switch selector in R1 under every C spelling (plain, named temps,
 * sel-first, alias pointer, no-temp, bitfield overlay, ushort selector,
 * volatile load, size pragma); the ROM has the field in R1 and the
 * selector in R2 (`ldr r1,[r0]; lsl r2,r1,#18; lsr r2,r2,#26`). Ten shapes
 * measured, all byte-identical except the 8 prologue/consumer words.
 * Pre-UAL mnemonics (this assembler predates PUSH/POP/LSL-alias forms). */

asm int *fn_0238A8F8(int *result) {
    LDR R1, [R0]
    MOV R2, R1, LSL #18
    MOV R2, R2, LSR #26
    CMP R2, #0x23
    ADDLS PC, PC, R2, LSL #2
    B L_def
    B L_a
    B L_a
    B L_a
    B L_a
    B L_a
    B L_a
    B L_a
    B L_a
    B L_a
    B L_a
    B L_def
    B L_def
    B L_def
    B L_def
    B L_def
    B L_def
    B L_a
    B L_a
    B L_b
    B L_b
    B L_b
    B L_b
    B L_b
    B L_b
    B L_b
    B L_b
    B L_def
    B L_def
    B L_def
    B L_def
    B L_def
    B L_def
    B L_c
    B L_c
    B L_b
    B L_b
L_a:
    BIC R1, R1, #0x4000
    STR R1, [R0]
    BX LR
L_b:
    ORR R1, R1, #0x4000
    STR R1, [R0]
    LDR R1, [R0]
    BIC R2, R1, #0x3F00
    MOV R1, R1, LSL #18
    MOV R1, R1, LSR #26
    SUB R1, R1, #0x12
    AND R1, R1, #0x3F
    ORR R1, R2, R1, LSL #8
    STR R1, [R0]
    BX LR
L_c:
    ORR R1, R1, #0x4000
    STR R1, [R0]
    LDR R1, [R0]
    BIC R2, R1, #0x3F00
    MOV R1, R1, LSL #18
    MOV R1, R1, LSR #26
    SUB R1, R1, #0x18
    AND R1, R1, #0x3F
    ORR R1, R2, R1, LSL #8
    STR R1, [R0]
    BX LR
L_def:
    LDR R1, [R0]
    BIC R1, R1, #0x4000
    STR R1, [R0]
    LDR R1, [R0]
    BIC R1, R1, #0x3F00
    STR R1, [R0]
    BX LR
}
