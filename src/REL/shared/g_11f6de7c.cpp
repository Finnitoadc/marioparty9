struct Obj {
    char pad[0x16];
    unsigned char field_16;
};

extern "C" void shared_g_11f6de7c(Obj* self, unsigned char v) {
    self->field_16 = v;
}
