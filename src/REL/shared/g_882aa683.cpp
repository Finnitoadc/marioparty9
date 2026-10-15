struct Obj {
    char pad[0x1C];
    unsigned char field_1C;
};

extern "C" void shared_g_882aa683(Obj* self) {
    self->field_1C = 1;
}
