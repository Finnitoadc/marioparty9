struct Obj {
    char pad[0xF8];
    int field_F8;
};

extern "C" void shared_g_1d9c1897(Obj* self) {
    self->field_F8 = 0;
}
