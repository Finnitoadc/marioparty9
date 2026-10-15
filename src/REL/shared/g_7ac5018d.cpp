struct O { void* p; };
extern "C" void fn_80055F60(void* p, int a);
extern "C" void fn_8020B5FC(void* p);
extern "C" O* shared_g_7ac5018d(O* self, int del) {
    if (self != 0) {
        fn_80055F60(self->p, 1);
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
