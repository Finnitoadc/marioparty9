extern "C" void fn_80041460(void* p, int a);
extern "C" void fn_8005CE40(void* p, int a);
extern "C" void fn_8020B5FC(void* p);

struct Obj {
    char pad0[0x148];
    int field_148;
};

extern "C" Obj* shared_g_56a97724(Obj* self, int del) {
    if (self != 0) {
        fn_80041460(&self->field_148, -1);
        if (self != 0) {
            fn_8005CE40(self, 0);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
