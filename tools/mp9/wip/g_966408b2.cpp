struct Vec {
    float x, y, z;
};

struct Handle {
    int v;
};

extern "C" void fn_800602F0(void* obj, float* out);
extern "C" void fn_80191FE0(float* a, float* m);
extern "C" void fn_80191D30(float* m, float* a, float* b);
extern "C" void fn_801928D0(float* m, Vec* a, Vec* b);
extern "C" int fn_80065DE0(void* obj);
extern "C" int fn_8010E9A0(Handle* h, char* name);
extern "C" void fn_80113B10(Handle* h, float x, float y, float z);

struct Obj {
    char pad0[8];
    unsigned flags;
    int pad_c;
    char* nameptr;
    char pad1[0x38];
    Vec field_4C;
    char pad2[0x4C];
    void* field_A4;
};


extern "C" void shared_g_966408b2(Obj* self, const Vec* v) {
    float x, y, z;
    z = v->z;
    y = v->y;
    x = v->x;
    self->field_4C.x = x;
    self->field_4C.y = y;
    self->field_4C.z = z;
    if (self->field_A4 != 0) {
        Vec c;
        float m[12];
        float a[12];
        fn_800602F0(self->field_A4, a);
        fn_80191FE0(a, m);
        fn_80191D30(m, a, a);
        fn_801928D0(m, &self->field_4C, &c);
        Handle h2;
        Handle h1;
        h1.v = fn_80065DE0(self->field_A4);
        h2.v = fn_8010E9A0(&h1, (self->flags >> 31) == 0 ? (char*)self + 9 : self->nameptr);
        fn_80113B10(&h2, c.x, c.y, c.z);
    }
}
