struct Obj { char pad[8]; unsigned char field_8; };
extern "C" void fn_80071590();
extern "C" void shared_g_9089126d(Obj* self) {
    while (self->field_8) fn_80071590();
}
