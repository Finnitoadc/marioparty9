struct Mtx {
    int m[12];
};

struct Obj {
    char pad0[0x84];
    Mtx field_84;
};

extern "C" void shared_g_3fac88bb(Obj* self, Mtx m) {
    self->field_84 = m;
}
