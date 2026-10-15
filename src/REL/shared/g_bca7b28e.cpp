extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* obj, int flags);
extern "C" void* shared_g_23fc310e(void* self, int del);

struct Obj {
    char pad[0x164];
    char field_164[0xC];
};

extern "C" Obj* shared_g_bca7b28e(Obj* self, int del) {
    if (self != 0) {
        fn_80071420(self->field_164, 0);
        shared_g_23fc310e(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
