extern "C" void fn_800728F0(unsigned int v, int flag);

struct Obj {
    unsigned int field_0;
};

extern "C" void shared_g_c3df5dde(Obj* self, unsigned int v) {
    unsigned int old = self->field_0;
    if (v != old) {
        self->field_0 = v;
        fn_800728F0(old, 1);
    }
}
