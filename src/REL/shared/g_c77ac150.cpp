struct Obj {
    char pad[0x39];
    unsigned char value;
    unsigned char locked;
};

extern "C" void shared_g_c77ac150(Obj* self, unsigned char v) {
    if (self->value == v) {
        return;
    }
    if (self->locked) {
        return;
    }
    self->value = v;
}
