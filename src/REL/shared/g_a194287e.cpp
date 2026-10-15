struct In { void* p; };
struct S { int pad; In* field_4; };
extern "C" void fn_8002FCD0(void* p);
extern "C" void shared_g_a194287e(S* self) {
    fn_8002FCD0(self->field_4->p);
}
