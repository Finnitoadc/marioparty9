struct Obj {
    char pad[0x1a0];
    int field_1A0;
};

extern "C" void shared_g_f35453cc(Obj* self, int v) {
    self->field_1A0 = v;
}
