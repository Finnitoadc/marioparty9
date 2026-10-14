extern "C" void fn_80086F10(void* obj, int flags);

extern "C" void shared_g_e4f40a20(void** self, void* v) {
    void* old = *self;
    if (v != old) {
        *self = v;
        fn_80086F10(old, 1);
    }
}
