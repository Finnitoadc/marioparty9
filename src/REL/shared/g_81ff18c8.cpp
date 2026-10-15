struct Obj {
    char pad[0x10C];
    int field_10C;
};

extern "C" void shared_g_81ff18c8(Obj* self, int v) {
    self->field_10C = v;
}
