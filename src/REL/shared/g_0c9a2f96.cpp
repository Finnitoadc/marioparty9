struct B { void* field_0; };
struct A { int pad; B* field_4; };
extern "C" void fn_8002F1D0(void* a, void* p);
extern "C" void shared_g_0c9a2f96(void* a, A* b) {
    fn_8002F1D0(a, b->field_4->field_0);
}
