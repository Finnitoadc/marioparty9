extern "C" void fn_8005DA50(void* p, void* a);
extern "C" void fn_8003F4B0(void* p, void* a);

struct Obj {
    int field_0;
    int field_4;
    void* field_8;
    void* field_c;
    void* field_10;
    void* field_14;
};

extern "C" void shared_g_6c532b0c(Obj* self, void* a) {
    fn_8005DA50(self->field_8, a);
    if (self->field_c != 0) {
        fn_8005DA50(self->field_c, a);
    }
    if (self->field_10 != 0) {
        fn_8003F4B0(self->field_10, a);
        if (self->field_14 != 0) {
            fn_8003F4B0(self->field_14, a);
        }
    }
}
