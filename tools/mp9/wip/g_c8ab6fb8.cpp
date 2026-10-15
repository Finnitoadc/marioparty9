extern "C" int fn_80189F10(void* p);

struct W { int v; };
struct Target {
    W field_0;
    int field_4;
    char field_8;
};

struct Obj {
    char pad0[4];
    unsigned char field_4;
    char pad1[0xF];
    Target* field_14;
    unsigned char field_18;
    W field_1C;
};

extern "C" void shared_g_c8ab6fb8(Obj* self) {
    if (self->field_4 != 0 && self->field_18 != 0) {
        Target* t = self->field_14;
        const W& v = self->field_1C;
        t->field_0 = v;
        t->field_4 = fn_80189F10(&t->field_8);
    }
    self->field_4 = 0;
}
