extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80041460(void* p, int a);
extern "C" void fn_8005CE40(void* p, int a);
extern "C" void fn_80071420(void* p, int a);

struct Obj {
    char pad[8];
    char m8[0x150];
    char m158[4];
};

extern "C" Obj* shared_g_968fc99d(Obj* self, int del) {
    if (self != 0) {
        fn_80041460(&self->m158, -1);
        if (&self->m8 != 0) {
            fn_8005CE40(&self->m8, 0);
        }
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
