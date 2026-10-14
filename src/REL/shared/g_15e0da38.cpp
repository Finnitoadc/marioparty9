struct Obj {
    char pad[0x9];
    unsigned char field_9;
};

extern "C" void shared_g_15e0da38(Obj* self) {
    self->field_9 = 1;
}
