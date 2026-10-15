struct A {
    char pad[0x5a4];
    unsigned field_5a4;
};
extern "C" void shared_g_8910a63a(A* self, int v) {
    if (v != 0) {
        self->field_5a4 |= 4;
    } else {
        self->field_5a4 &= ~4u;
    }
}
