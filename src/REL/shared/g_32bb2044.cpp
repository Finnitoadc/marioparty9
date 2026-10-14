struct Obj {
    char pad[0x74];
    int field_74;
};

extern "C" void shared_g_32bb2044(Obj* self, int v) {
    self->field_74 = v;
}
