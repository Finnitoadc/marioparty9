struct Vec { float x, y, z; };
extern "C" float lbl_8026E3B4;

static inline void VecScale(register const Vec* src, register unsigned dst, register float scale) {
    register float r, x;
    asm {
        psq_l x, 0(src), 0, 0
        ps_muls0 r, x, scale
        psq_l x, 8(src), 1, 0
        psq_st r, 0(dst), 0, 0
        ps_muls0 r, x, scale
        psq_st r, 8(dst), 1, 0
    }
}

static inline void VecAdd(register const Vec* a, register unsigned b, register Vec* dst) {
    register float x, y, r;
    asm {
        psq_l x, 0(a), 0, 0
        psq_l y, 0(b), 0, 0
        ps_add r, x, y
        psq_l x, 8(a), 1, 0
        psq_l y, 8(b), 1, 0
        psq_st r, 0(dst), 0, 0
        ps_add r, x, y
        psq_st r, 8(dst), 1, 0
    }
}

struct S { char pad[0x620]; Vec field_620; };

extern "C" void shared_g_aa9e2eb8(S* self, const Vec* v) {
    Vec t;
    VecScale(v, (unsigned)&t, lbl_8026E3B4);
    VecAdd(&self->field_620, (unsigned)&t, &self->field_620);
}
