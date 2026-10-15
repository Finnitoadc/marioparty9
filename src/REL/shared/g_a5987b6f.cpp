extern "C" void fn_80071590();
struct Obj { char pad[0x28]; int field_28; };
extern "C" void shared_g_a5987b6f(Obj* self) {
    while (self->field_28 != 0) fn_80071590();
}
