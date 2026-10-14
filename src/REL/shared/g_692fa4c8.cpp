struct Obj {
    char pad[0x24];
    float field_24[4];
};

extern "C" void shared_g_692fa4c8(Obj* self, int i, float v) {
    if (i < 4) {
        self->field_24[i] = v;
    }
}
