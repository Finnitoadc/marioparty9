extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80046040(void* res, int flags);

extern "C" void* shared_g_049107ea(void* self, int del) {
    if (self != 0) {
        fn_80046040(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
