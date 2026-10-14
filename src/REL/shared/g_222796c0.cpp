struct Obj {
    char pad[0x150];
    float field_150;
};

extern "C" void shared_g_222796c0(Obj* self, float v) {
    self->field_150 = v;
}
