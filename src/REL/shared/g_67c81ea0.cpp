struct Obj {
    char pad[0x1C];
    int field_1C;
};

extern "C" void shared_g_67c81ea0(Obj* self, int v) {
    self->field_1C = v;
}
