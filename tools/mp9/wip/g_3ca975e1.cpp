struct Vec { float x, y, z; };
extern "C" void fn_8002CD90(void* obj, Vec* v);
extern "C" void fn_8002D7A0(void* obj, Vec* v);

static inline void vadd(register const Vec* a, register const Vec* b, register Vec* out) {
    register float x, y, r;
    asm {
        psq_l x, 0(a), 0, 0
        psq_l y, 0(b), 0, 0
        ps_add r, x, y
        psq_l x, 8(a), 1, 0
        psq_l y, 8(b), 1, 0
        psq_st r, 0(out), 0, 0
        ps_add r, x, y
        psq_st r, 8(out), 1, 0
    }
}

struct Obj { char pad[0x124]; Vec a; Vec b; Vec off; };

extern "C" void shared_g_3ca975e1(Obj* self, Vec* pos, Vec* rot) {
    Vec t;
    vadd(pos, &self->off, &t);
    fn_8002CD90(self, &t);
    self->a = *pos;
    Vec u;
    vadd(rot, &self->off, &u);
    fn_8002D7A0(self, &u);
    self->b = *rot;
}
