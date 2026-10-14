struct Obj {
    int field_00;
    int field_04;
    int field_08;
};

extern "C" void shared_g_4526e6ee(Obj* self, int a, int b) {
    self->field_04 = a;
    self->field_08 = b;
}
