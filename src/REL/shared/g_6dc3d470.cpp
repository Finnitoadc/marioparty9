struct B { void* field_0; };
struct A { int pad; B* field_4; };
extern "C" void fn_8002C6B0(void* p);
extern "C" void shared_g_6dc3d470(A* self) {
    fn_8002C6B0(self->field_4->field_0);
}
