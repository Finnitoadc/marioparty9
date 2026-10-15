struct B {
    char pad[8];
    unsigned char field_08;
};
struct A {
    char pad[0x30];
    B* field_30;
};
extern "C" unsigned lbl_8026E2A4;
extern "C" void shared_g_5f9cf22c(A* self) {
    if (self->field_30->field_08 == 0) lbl_8026E2A4 |= 0x100;
}
