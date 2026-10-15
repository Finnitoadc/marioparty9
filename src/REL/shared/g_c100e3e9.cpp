struct Obj { char pad[0x48]; int field_48; };
extern "C" void shared_g_c100e3e9(Obj* self, int v) {
    self->field_48 = v;
}
