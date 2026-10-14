struct Obj {
    char pad[0x18];
    int value;
};

extern "C" void shared_g_19ec8442(Obj* self, int v) {
    self->value = v > 999 ? 999 : v;
}
