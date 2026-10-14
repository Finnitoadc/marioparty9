struct Mtx {
    float m[3][4];
};

extern "C" void fn_80191CF0(Mtx* src, Mtx* dst);
extern "C" void fn_80191D30(Mtx* a, Mtx* b, Mtx* ab);
extern "C" void fn_80060270(void* obj, Mtx m);

struct Child {
    virtual void v0();
    virtual void SetPos(float x, float y, float z);
};

struct Parent {
    char pad[0x168];
    Mtx mtx;
};

struct Obj {
    char pad[0x8];
    float x;
    float y;
    float z;
    char pad2[0xD4];
    Mtx base;
    char pad3[0x44];
    void* field_15c;
    Child* field_160;
    Parent* field_164;
    Mtx mtx;
};

extern "C" void shared_g_24e6596a(Obj* self, float x, float y, float z) {
    self->x = x;
    self->y = y;
    self->z = z;
    fn_80191CF0(&self->base, &self->mtx);
    self->mtx.m[0][3] = self->x;
    self->mtx.m[1][3] = self->y;
    self->mtx.m[2][3] = self->z;
    if (self->field_164 != 0) {
        fn_80191D30(&self->field_164->mtx, &self->mtx, &self->mtx);
    }
    void* p = self->field_15c;
    if (p != 0) {
        fn_80060270(p, self->mtx);
    }
    if (self->field_160 != 0) {
        self->field_160->SetPos(x, y, z);
    }
}
