struct Obj {
    char pad[0x210];
    unsigned char field_210;
};

extern "C" void shared_g_cfdc567b(Obj* self, unsigned char v) {
    if (self->field_210 != v) {
        self->field_210 = v;
    }
}
