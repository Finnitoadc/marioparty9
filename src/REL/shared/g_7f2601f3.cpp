struct Obj {
    char pad[0x3c4];
    unsigned field_3C4;
};

extern "C" void shared_g_7f2601f3(Obj* self, int v) {
    if (v) {
        self->field_3C4 |= 1;
    } else {
        self->field_3C4 &= ~1;
    }
}
