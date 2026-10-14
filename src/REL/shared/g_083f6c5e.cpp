extern "C" void fn_8005DA50(void* p, int on);

struct Obj {
    char pad[0x10];
    void* field_10;
    char pad2[0x2C];
    void* field_40;
};

extern "C" void shared_g_083f6c5e(Obj* self, int on) {
    fn_8005DA50(self->field_40, on);
    if (self->field_10) {
        fn_8005DA50(self->field_10, on);
    }
}
