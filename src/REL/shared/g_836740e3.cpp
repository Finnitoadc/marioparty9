struct Obj { char pad[0x60]; int field_60; };
extern "C" void shared_g_836740e3(Obj* self, int v) {
    self->field_60 = v;
}
