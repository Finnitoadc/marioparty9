extern "C" void fn_8020B5FC(void* obj);

extern "C" void shared_g_8f243731(void** self, void* v) {
    void* old = *self;
    if (v != old) {
        *self = v;
        fn_8020B5FC(old);
    }
}
