struct B {
    char pad[0x22];
    unsigned char field_22;
};

struct A {
    char pad[0x148];
    B* field_148;
};

extern "C" void shared_g_a6fcb9a6(A* self, unsigned char v) {
    self->field_148->field_22 = v;
}
