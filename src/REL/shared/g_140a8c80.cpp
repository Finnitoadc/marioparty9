struct Obj {
    char pad[0x165];
    unsigned char field_165;
};

extern "C" void shared_g_140a8c80(Obj* self, unsigned char v) {
    self->field_165 = v;
}
