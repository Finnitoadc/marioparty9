struct Obj {
    char pad[0x10];
    int field_10;
};

extern "C" void shared_g_23cbdbe4(Obj* self, int v) {
    self->field_10 = v;
}
