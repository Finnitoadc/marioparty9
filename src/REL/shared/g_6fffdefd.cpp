extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80086F10(void* obj, int flags);

extern "C" char* shared_g_6fffdefd(char* self, int del) {
    if (self != 0) {
        fn_80086F10(self + 4, -1);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
