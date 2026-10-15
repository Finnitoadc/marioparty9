struct Vec {
    float x, y, z;
};
struct Mtx {
    int m[12];
};

extern "C" Mtx* fn_800602E0(void* p);
extern "C" void fn_801928D0(Mtx* m, int a, Vec* out);

struct Obj {
    char pad[0x68];
    char field_68[0x8E0];
    Vec field_948;
    float field_954;
    char pad2[0x14];
    int field_96c;
    char pad3[8];
    unsigned char field_978;
    char pad4[0x1F];
    unsigned char field_998;
};

extern "C" void shared_g_a0ea0a60(Obj* self, int a, unsigned char b, float f) {
    Vec v;
    Mtx m;
    Mtx* s = fn_800602E0(self->field_68);
    for (int i = 0; i < 12; i += 2) {
        int x = s->m[i];
        int y = s->m[i + 1];
        m.m[i + 1] = y;
        m.m[i] = x;
    }
    fn_801928D0(&m, a, &v);
    self->field_96c = 0;
    self->field_948 = v;
    self->field_954 = f;
    self->field_978 = b;
    self->field_998 = 1;
}
