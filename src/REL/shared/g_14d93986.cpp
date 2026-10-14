extern "C" void fn_8002AE40(void* obj, int flag);

struct Ref {
    void* p;
};

extern "C" void shared_g_14d93986(Ref* self, void* p) {
    void* old = self->p;
    if (p != old) {
        self->p = p;
        fn_8002AE40(old, 1);
    }
}
