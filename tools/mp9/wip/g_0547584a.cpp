// Only diff: epilogue order (target: lwz r0 before psq_l f31)
extern "C" void fn_80060200(void* p, float f);
extern "C" void fn_8003F590(void* p, float f);

struct Obj {
    int field_0;
    int field_4;
    void* field_8;
    void* field_c;
    void* field_10;
    void* field_14;
    float field_18;
};

extern "C" void shared_g_0547584a(Obj* self, float f) {
    fn_80060200(self->field_8, f);
    if (self->field_c != 0) {
        fn_80060200(self->field_c, f * self->field_18);
    }
    if (self->field_10 == 0) {
        return;
    }
    fn_8003F590(self->field_10, f);
    if (self->field_14 == 0) {
        return;
    }
    fn_8003F590(self->field_14, f);
}
