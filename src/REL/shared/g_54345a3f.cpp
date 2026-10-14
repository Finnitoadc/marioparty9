struct Obj {
    char pad[0x28];
    float field_28;
};

extern "C" void shared_g_54345a3f(Obj* self, float v) {
    self->field_28 = v;
}
