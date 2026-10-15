struct In { char pad[0x188]; int m; };
struct Obj { char pad[0x328]; In* field_328; };
extern "C" int fn_8020C6D8(void* p);
extern "C" void fn_8020C7DC(void* p, int a);
extern "C" void shared_g_49b417b0(Obj* self) {
    if (fn_8020C6D8(self->field_328->pad + 0x188) == 0) fn_8020C7DC(self->field_328, 1);
}
