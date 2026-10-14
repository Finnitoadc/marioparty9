extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* p, int v);
extern "C" void fn_80046040(void* p, int v);

extern "C" char* shared_g_a84a6503(char* self, int del) {
    if (self != 0) {
        fn_80071420(self + 4, 0);
        fn_80046040(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
