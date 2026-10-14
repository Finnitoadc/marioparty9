struct Obj {
    char pad[0x8];
    unsigned char field_08;
};

extern "C" void shared_g_39dd4e53(Obj* self) {
    self->field_08 = 0;
}
