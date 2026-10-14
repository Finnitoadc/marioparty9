extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* self, int flags);

extern "C" void* shared_g_584ef421(void* self, int del) {
    if (self != 0) {
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
