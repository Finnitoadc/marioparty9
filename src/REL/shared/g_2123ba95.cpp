extern "C" void fn_8003F020(void* p, int n);

extern "C" void shared_g_2123ba95(void** self, void* p) {
    void* old = *self;
    if (p != old) {
        *self = p;
        fn_8003F020(old, 1);
    }
}
