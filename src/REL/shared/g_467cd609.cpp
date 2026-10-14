struct Obj {
    int field_00;
    int field_04;
};

extern "C" void shared_g_467cd609(Obj* self, int a, int b) {
    self->field_00 = a;
    self->field_04 = b;
}
