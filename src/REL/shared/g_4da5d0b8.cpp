extern "C" void fn_8005D970(void* p, int a);
extern "C" void fn_8003F480(void* p, int a);

struct Obj {
    int field_0;
    int field_4;
    void* field_8;
    void* field_c;
    void* field_10;
    void* field_14;
};

extern "C" void shared_g_4da5d0b8(Obj* self, int a) {
    fn_8005D970(self->field_8, a);
    if (self->field_c != 0) {
        fn_8005D970(self->field_c, a);
    }
    if (self->field_10 != 0) {
        fn_8003F480(self->field_10, a);
        if (self->field_14 != 0) {
            fn_8003F480(self->field_14, a);
        }
    }
}
