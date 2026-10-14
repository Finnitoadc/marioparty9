struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec& o) : x(o.x), y(o.y), z(o.z) {}
    Vec& operator=(const Vec& o) {
        x = o.x;
        y = o.y;
        z = o.z;
        return *this;
    }
};

extern "C" Vec* fn_80060100(void* p);
extern "C" void fn_8007E0C0(int id, Vec* v);

static inline void VecAdd(register const Vec* a, register const Vec* b, register Vec* out) {
    asm {
        psq_l f0, 0(a), 0, 0
        psq_l f1, 0(b), 0, 0
        ps_add f0, f0, f1
        psq_l f1, 8(b), 1, 0
        psq_st f0, 0(out), 0, 0
        psq_l f0, 8(a), 1, 0
        ps_add f0, f0, f1
        psq_st f0, 8(out), 1, 0
    }
}

struct Obj {
    char pad[0x1C];
    void* field_1C;
    Vec field_20;
    char pad2C[0xDE - 0x2C];
    unsigned char field_DE;
    char padDF[0x11C - 0xDF];
    int field_11C;
    int field_120;
};

extern "C" void shared_g_11a593a4(Obj* self, const Vec& v) {
    self->field_20 = v;
    if (self->field_120 != -1 && self->field_DE == 1) {
        Vec tmp = self->field_20;
        Vec out;
        VecAdd(fn_80060100(self->field_1C), &tmp, &out);
        fn_8007E0C0(self->field_120, &out);
    }
    if (self->field_11C != -1 && self->field_DE == 1) {
        Vec tmp = self->field_20;
        Vec out;
        VecAdd(fn_80060100(self->field_1C), &tmp, &out);
        fn_8007E0C0(self->field_11C, &out);
    }
}
