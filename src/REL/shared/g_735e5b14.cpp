struct Obj {
    char pad[0xDC];
    unsigned char field_DC;
};

extern "C" void shared_g_735e5b14(Obj* self, unsigned char v) {
    self->field_DC = v;
}
