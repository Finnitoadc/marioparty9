struct Obj {
    char pad[0x20];
    unsigned char field_20;
};

extern "C" void shared_g_69f4c180(Obj* self, unsigned char v) {
    self->field_20 = v;
}
