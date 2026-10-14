struct Obj {
    char pad[0x18];
    int value;
};

extern "C" void shared_g_42c3756b(Obj* self, int v) {
    self->value = v > 10 ? 10 : v;
}
