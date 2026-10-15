extern "C" void* fn_80070680(int);
extern "C" void fn_8006DDE0(void*, int);
struct Obj { char pad[0x34]; int field_34; };
extern "C" void shared_g_faf3b7be(Obj* self, int a) {
    fn_8006DDE0(fn_80070680(0), a);
    self->field_34 = -1;
}
