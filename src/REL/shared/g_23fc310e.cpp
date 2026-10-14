extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80086F10(void* obj, int flags);
extern "C" void fn_8005CE40(void* self, int flags);

extern "C" void* shared_g_23fc310e(char* self, int del) {
    if (self != 0) {
        char* a = self + 0x158;
        if (a != 0) {
            fn_80086F10(a + 4, -1);
        }
        char* b = self + 0x150;
        if (b != 0) {
            fn_80086F10(b + 4, -1);
        }
        fn_8005CE40(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
