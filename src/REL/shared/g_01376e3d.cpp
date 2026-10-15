struct Obj { char pad[0xc]; float field_c; };
extern "C" void shared_g_01376e3d(Obj* self, float* p) { self->field_c = *p; }
