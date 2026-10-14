extern "C" void fn_80055F60(void* obj, int flags);

extern "C" void shared_g_e1422d63(void** self, void* v) {
    void* old = *self;
    if (v != old) {
        *self = v;
        fn_80055F60(old, 1);
    }
}
