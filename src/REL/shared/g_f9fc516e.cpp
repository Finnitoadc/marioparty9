extern "C" void fn_8007E0C0(int, int);
struct Obj { char pad[0x954]; int field_954; };
extern "C" void shared_g_f9fc516e(Obj* self, int a, int b) {
    if (self->field_954 != 0 && a == -1) return;
    fn_8007E0C0(a, b);
}
