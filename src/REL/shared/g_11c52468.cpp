struct Obj { char pad[0x5a4]; unsigned field_5a4; };
extern "C" void shared_g_11c52468(Obj* self, int f) {
    if (f != 0) self->field_5a4 |= 1; else self->field_5a4 &= ~1u;
}
