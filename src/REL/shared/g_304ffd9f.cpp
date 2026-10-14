struct Obj {
    char pad[0x170];
    float field_170;
};

extern "C" void shared_g_304ffd9f(Obj* self, float v) {
    self->field_170 = v;
}
