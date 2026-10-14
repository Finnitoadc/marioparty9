extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80086F10(void* p, int del);

struct Obj {
    int field_00;
    char field_04[0x4];
};

extern "C" Obj* shared_g_776cb955(Obj* self, int del) {
    if (self != 0) {
        if (self != 0) {
            fn_80086F10(self->field_04, -1);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
