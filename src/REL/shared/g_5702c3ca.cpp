extern "C" void fn_8003E110(void* obj, int flags);

extern "C" void shared_g_5702c3ca(void** self, void* v) {
    void* old = *self;
    if (v != old) {
        *self = v;
        fn_8003E110(old, 1);
    }
}
