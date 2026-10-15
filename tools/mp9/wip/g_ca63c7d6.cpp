struct Vec {
    float x, y, z;
};

static inline asm void vscale(register Vec* dst, register const Vec* src, register float s) {
    psq_l f2, 0(src), 0, 0
    ps_muls0 f0, f2, s
    psq_l f2, 8(src), 1, 0
    psq_st f0, 0(dst), 0, 0
    ps_muls0 f0, f2, s
    psq_st f0, 8(dst), 1, 0
}

struct Obj {
    char pad[4];
    Vec pos;
    float scale;
};

extern "C" int shared_g_ca63c7d6(Obj* self, const Vec* dir, Vec* out) {
    Vec t;
    vscale(&t, dir, self->scale);
    out->x = self->pos.x + t.x;
    out->y = self->pos.y + t.y;
    out->z = self->pos.z + t.z;
    return 1;
}
