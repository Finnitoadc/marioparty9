struct Obj {
    char pad[0x290];
    unsigned char field_290;
};

extern "C" void shared_g_f4211936(Obj* self) {
    self->field_290 = 1;
}
