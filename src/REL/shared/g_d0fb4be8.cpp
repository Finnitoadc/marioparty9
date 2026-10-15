struct Obj {
    char pad[0x28];
    unsigned char field_28;
};
extern "C" void shared_g_d0fb4be8(Obj* self, int v) {
    self->field_28 = v;
}
