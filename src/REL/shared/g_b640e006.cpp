extern "C" void fn_8020B5FC(void* ptr);

extern "C" void* shared_g_b640e006(void* self, int del) {
    if (self != 0 && del > 0) {
        fn_8020B5FC(self);
    }
    return self;
}
