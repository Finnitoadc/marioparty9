struct Obj {
    char pad[0x2c];
    int field_2C;
};

extern "C" void shared_g_eb901d7f(Obj* self, int v) {
    self->field_2C = v;
}
