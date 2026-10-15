extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80055F60(void* obj, int flags);

extern "C" void* shared_g_8644c4dd(void* self, int del) {
    if (self != 0) {
        fn_80055F60(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
