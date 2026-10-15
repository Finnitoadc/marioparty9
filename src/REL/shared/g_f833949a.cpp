struct Obj { char pad[0x184]; float field_184; };

extern "C" void shared_g_f833949a(Obj* self, float v) {
    self->field_184 = v;
}
