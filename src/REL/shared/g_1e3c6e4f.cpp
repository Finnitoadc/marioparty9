struct In {
    char pad[0x23];
    unsigned char field_23;
};

struct Obj {
    char pad[0x148];
    In* field_148;
};

extern "C" void shared_g_1e3c6e4f(Obj* self, unsigned char v) {
    self->field_148->field_23 = v;
}
