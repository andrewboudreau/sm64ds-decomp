extern void fn_02382C98(void *a1, void *a2, int a3) /* =0x037FAB30 */;
extern int fn_0238D594(int a1, int a2) /* =0x0380542C */;
extern int fn_02394D84(void *a1, void *a2, unsigned short *node) /* =0x027C6CFC */;
extern void fn_0239477C(int a1, int a2) /* =0x027C66F4 */;
extern int fn_02394DF8(void *list, unsigned short *node) /* =0x027C6D70 */;

#pragma opt_propagation off
#pragma opt_common_subs off
void fn_023A0CE0(unsigned short *a1, int a2, int a3) {
    unsigned short *v12;
    unsigned int sh;
    char *base;
    unsigned int sum;
    unsigned int i;
    unsigned int hi8;
    unsigned int hi9;
    int off;
    char *slot;
    unsigned int w9;
    int v13;
    char *slot16;
    int r;
    unsigned int w8;
    unsigned short cur;
    int diff;
    unsigned int nib;
    base = *(char **)0x0380FFF4 + 0x4A0;
    a1[4] -= 24;
    for (i = 0; i < 3; i++) {
        off = i * 0x18;
        unsigned short *lslot = (unsigned short *)(base + off);
        if (*(unsigned short *)(base + off) != 0
            && ((unsigned short *)a2)[2] == lslot[4]
            && ((unsigned short *)a2)[1] == lslot[3]
            && ((unsigned short *)a2)[0] == lslot[2]
            && ((unsigned short *)a2)[5] == lslot[7]
            && ((unsigned short *)a2)[4] == lslot[6]
            && ((unsigned short *)a2)[3] == lslot[5]) {
            w8 = ((unsigned short *)a2)[6];
            hi8 = (w8 << 16) >> 20;
            w9 = lslot[8];
            hi9 = (w9 << 16) >> 20;
            if (hi8 == hi9) {
                diff = w9 - w8;
                if ((diff & 0x80000000) != 0)
                    return;
                a2 = diff * lslot[1];
                a3 = (int)a1[4] - a2;
                if (a3 == 0)
                    return;
                if ((a3 & 0x80000000) != 0)
                    return;
                break;
            }
        }
    }
    if (i != 3) {
        off = i * 0x18;
        slot = base + off;
        v12 = (unsigned short *)(*(int *)(slot + 20) + 16);
        v13 = v12[8];
        sum = v13 + a3;
        if (sum > 0x5E4) {
            fn_02394DF8((*(char **)0x0380FFF4 + 0x14C), (v12 - 8));
            *(unsigned short *)(base + off) = 0;
        } else {
            fn_02382C98((char *)&a1[18] + a2, (void *)((char *)v12 + 44 + v13), a3 + 1);
            v12[8] = (unsigned short)sum;
            r = fn_0238D594(*a1 & 0xF0, 16);
            slot = base + off;
            slot16 = slot + 16;
            cur = *(unsigned short *)slot16;
            sh = (unsigned int)cur << 28;
            *(unsigned short *)slot16 = (unsigned short)((cur & ~0xF) | ((unsigned short)(r - diff + (sh >> 28)) & 0xF));
            *(int *)((char *)*(char **)0x0380FFF4 + 0x518) += r;
            if ((*a1 & 0x100) == 0) {
                *(unsigned short *)slot = 0;
                v12[4] = (unsigned short)((v12[4] & ~0xF0) + 0x10);
                v12[8] += 24;
                nib = v12[4] & 0xF;
                if (nib == 0)
                    goto do17;
                if (nib != 8)
                    goto doC;
                fn_02394D84((*(char **)0x0380FFF4 + 0x14C), (*(char **)0x0380FFF4 + 0x188), (v12 - 8));
                fn_0239477C(2, 6);
                goto done;
            do17:
                fn_02394D84((*(char **)0x0380FFF4 + 0x14C), (*(char **)0x0380FFF4 + 0x1A0), (v12 - 8));
                fn_0239477C(1, 7);
                goto done;
            doC:
                fn_02394DF8((*(char **)0x0380FFF4 + 0x14C), (v12 - 8));
            done:;
            }
        }
    }
}
