struct In { void* p; };
struct S { int pad; In* field_4; };
extern "C" void fn_8002CFD0(void* a, void* p);
extern "C" void shared_g_8873d608(void* a, S* b) {
    fn_8002CFD0(a, b->field_4->p);
}
