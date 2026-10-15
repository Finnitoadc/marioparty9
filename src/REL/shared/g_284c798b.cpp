struct Obj {
    char pad[4];
    unsigned char field_4;
};

extern "C" void shared_g_284c798b(Obj* self) {
    self->field_4 = 0;
}
