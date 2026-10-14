struct Obj {
    char pad[0x8];
    unsigned char field_8;
};

extern "C" void shared_g_6229ec4a(Obj* self, unsigned char v) {
    self->field_8 = v;
}
