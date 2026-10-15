struct Q4 { float a, b, c, d; };
struct Mtx { float m[12]; };

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(void* x);
};

struct Parent { char pad[0x168]; };

struct Obj {
    char pad0[8];
    float field_8, field_C, field_10;
    char pad1[0x14 - 0x14];
    Q4 q;
    char pad2[0xE8 - 0x24];
    char field_E8[0x118 - 0xE8];
    char field_118[0x15C - 0x118 - 0x0];
    void* field_15C;
    Sub* field_160;
    Parent* field_164;
    Mtx field_168;
};

extern "C" void fn_80192460(void* a, void* b);
extern "C" void fn_80191F90(void* a, void* b);
extern "C" void fn_80191CF0(void* a, void* b);
extern "C" void fn_80191D30(void* a, void* b, void* c);
extern "C" void fn_80060270(void* a, Mtx m);

extern "C" void shared_g_e56e2ae4(Obj* self, float* src) {
    self->q = *(Q4*)src;
    fn_80192460(self->field_E8, &self->q);
    fn_80191F90(self->field_E8, self->field_118);
    fn_80191CF0(self->field_E8, &self->field_168);
    self->field_168.m[3] = self->field_8;
    self->field_168.m[7] = self->field_C;
    self->field_168.m[11] = self->field_10;
    if (self->field_164 != 0) {
        fn_80191D30((char*)self->field_164 + 0x168, &self->field_168, &self->field_168);
    }
    void* o = self->field_15C;
    if (o != 0) {
        fn_80060270(o, self->field_168);
    }
    if (self->field_160 != 0) {
        self->field_160->v4(self->field_E8);
    }
}
