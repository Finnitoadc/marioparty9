extern "C" void fn_8020B5FC(void*);
extern "C" void fn_8005CE40(void* self, int flags);
extern "C" void* shared_g_a6e988cb(void* self, int del) {
    if (self != 0) {
        fn_8005CE40(self, 0);
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
