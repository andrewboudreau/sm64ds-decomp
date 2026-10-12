/* storage 0x02382EF0 runtime 0x037FAD88 size 0x8 wram ARM.
 * Atomic swap (SWP R0,R0,[R1]). No pool. */

unsigned int fn_02382EF0(unsigned int a1, unsigned int *a2) {
    __asm {
        SWP R0, R0, [R1]
    }
}
