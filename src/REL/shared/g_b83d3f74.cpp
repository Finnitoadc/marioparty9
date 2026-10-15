struct Obj {
    char pad[0x3c4];
    unsigned field_3C4;
};

extern "C" void shared_g_b83d3f74(Obj* self, int v) {
    if (v) {
        self->field_3C4 |= 2;
    } else {
        self->field_3C4 &= ~2;
    }
}
