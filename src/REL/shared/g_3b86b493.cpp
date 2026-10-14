extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80046040(void* res, int flags);
extern "C" void fn_80071420(void* self, int del);

struct Obj {
    char pad[0x14];
    int field_14;
};

extern "C" Obj* shared_g_3b86b493(Obj* self, int del) {
    if (self != 0) {
        fn_80046040(&self->field_14, 0);
        if (self != 0) {
            fn_80071420(self, 0);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
