struct Obj {
    char pad[0x22];
    unsigned char field_22;
    unsigned char field_23;
};

extern "C" void shared_g_6eae5f93(Obj* self) {
    self->field_22 = 1;
    self->field_23 = 0;
}
