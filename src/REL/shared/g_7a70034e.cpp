struct Obj {
    char pad[0x18];
    int value;
};

extern "C" void shared_g_7a70034e(Obj* self, int v) {
    self->value = v > 9 ? 9 : v;
}
