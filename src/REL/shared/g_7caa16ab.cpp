extern "C" void fn_80071420(void* p, int a);
extern "C" void fn_8005CE40(void* p, int a);
extern "C" void fn_8020B5FC(void* p);
struct S { char pad[0x148]; int m; };
extern "C" S* shared_g_7caa16ab(S* self, int del) {
    if (self != 0) {
        fn_80071420(&self->m, 0);
        fn_8005CE40(self, 0);
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
