extern "C" void fn_8020B5FC(void* p);
extern "C" void fn_80041460(void* p, int x);
extern "C" void fn_8005CE40(void* p, int x);

struct Obj {
    char pad0[0x148];
    int field_148;
};

extern "C" Obj* shared_g_64d7b098(Obj* self, int del) {
    if (self != 0) {
        fn_80041460(&self->field_148, 0);
        if (self != 0) {
            fn_8005CE40(self, 0);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
