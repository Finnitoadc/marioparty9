struct Vec { float x, y, z; };
extern "C" float lbl_8026E3B4;

asm inline void VecScale(register const Vec* src, register Vec* dst, register float scale) {
    psq_l f1, 0(src), 0, 0
    ps_muls0 f2, f1, scale
    psq_l f1, 8(src), 1, 0
    psq_st f2, 0(dst), 0, 0
    ps_muls0 f2, f1, scale
    psq_st f2, 8(dst), 1, 0
}

asm inline void VecAdd(register const Vec* a, register const Vec* b, register Vec* dst) {
    psq_l f2, 0(a), 0, 0
    psq_l f1, 0(b), 0, 0
    ps_add f0, f2, f1
    psq_l f2, 8(a), 1, 0
    psq_l f1, 8(b), 1, 0
    psq_st f0, 0(dst), 0, 0
    ps_add f0, f2, f1
    psq_st f0, 8(dst), 1, 0
}

struct S { char pad[0x620]; Vec field_620; };

extern "C" void shared_g_aa9e2eb8(S* self, const Vec* v) {
    Vec t;
    VecScale(v, &t, lbl_8026E3B4);
    VecAdd(&self->field_620, &t, &self->field_620);
}
