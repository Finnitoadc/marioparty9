struct A {
    char pad[0x5a4];
    unsigned field_5a4;
};
extern "C" void shared_g_c4acbbd3(A* self, int v) {
    unsigned m = -(v != 0);
    self->field_5a4 = (self->field_5a4 & ~2u) | (m & 2);
}
