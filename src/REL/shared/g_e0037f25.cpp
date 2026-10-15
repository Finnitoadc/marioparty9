struct Vec {
    float x, y, z;
};
struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2(Vec*);
};
struct Mtx {
    float m[3][4];
};
struct Other {
    char pad[0x168];
    Mtx mtx;
};
struct Obj {
    char pad[8];
    Vec pos;
    char pad2[0xD4];
    float mtx_e8[1];
    char pad3[0x70];
    Sub* field_15c;
    Sub* field_160;
    Other* field_164;
    Mtx mtx;
};
extern "C" void fn_80191CF0(void*, void*);
extern "C" void fn_80191D30(void*, void*, void*);
extern "C" void fn_80060270(void*, void*);
extern "C" void shared_g_e0037f25(Obj* self, Vec* v) {
    self->pos.x = v->x;
    self->pos.y = v->y;
    self->pos.z = v->z;
    fn_80191CF0(self->mtx_e8, &self->mtx);
    self->mtx.m[0][3] = self->pos.x;
    self->mtx.m[1][3] = self->pos.y;
    self->mtx.m[2][3] = self->pos.z;
    if (self->field_164 != 0) {
        fn_80191D30(&self->field_164->mtx, &self->mtx, &self->mtx);
    }
    if (self->field_15c != 0) {
        fn_80060270(self->field_15c, &self->mtx);
    }
    if (self->field_160 != 0) {
        self->field_160->v2(v);
    }
}
