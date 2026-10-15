struct Obj { char pad[0x1c]; int field_1c; };
extern "C" void shared_g_fa086e2f(Obj* self, int f) {
    if (f != 0) self->field_1c = 0x10f; else self->field_1c = 0;
}
