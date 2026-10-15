struct Obj {
    char pad[0x16A];
    unsigned char field_16A;
    unsigned char field_16B;
};

extern "C" void shared_g_90c43f45(Obj* self, unsigned char a, unsigned char b) {
    self->field_16A = a;
    self->field_16B = b;
}
