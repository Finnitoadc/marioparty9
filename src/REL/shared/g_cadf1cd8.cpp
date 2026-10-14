struct Obj {
    char pad[0x18];
    int value;
    char pad2[0x14];
    int max;
};

extern "C" void shared_g_cadf1cd8(Obj* self, int v) {
    if (v > self->max) {
        v = self->max;
    }
    self->value = v;
}
