struct Obj {
    char pad[0x18];
    int value;
};

extern "C" void shared_g_7875277f(Obj* self, int v) {
    self->value = v > 99 ? 99 : v;
}
