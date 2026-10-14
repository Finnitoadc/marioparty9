struct Obj {
    char pad[0x18];
    int value;
};

extern "C" void shared_g_c1ab5c7a(Obj* self, int v) {
    self->value = v > 8 ? 8 : v;
}
