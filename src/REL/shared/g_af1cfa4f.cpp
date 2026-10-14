extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_8006AFD0(void* self, int flags);

extern "C" void* shared_g_af1cfa4f(void* self, int del) {
    if (self != 0) {
        fn_8006AFD0(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
