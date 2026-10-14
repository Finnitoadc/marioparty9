struct Obj {
    char pad[0x18];
    int value;
};

extern "C" void shared_g_ea257b7c(Obj* self, int v) {
    self->value = v > 5 ? 5 : v;
}
