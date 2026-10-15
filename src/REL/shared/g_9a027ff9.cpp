struct Obj {
    char pad[0x50];
    unsigned char field_50;
};

extern "C" void shared_g_9a027ff9(Obj* self, unsigned char v) {
    self->field_50 = v;
}
