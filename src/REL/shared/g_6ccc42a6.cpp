struct Obj {
    char pad[0xE4];
    float field_E4;
};

extern "C" void shared_g_6ccc42a6(Obj* self, float v) {
    self->field_E4 = v;
}
