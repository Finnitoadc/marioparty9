struct B { char pad[4]; void* field_04; };
struct A { char pad[4]; B* field_04; };
extern "C" void shared_g_ac27d302(void* self, int on);
extern "C" void shared_g_d286b5ad(A* self, int on) {
    shared_g_ac27d302(*(void**)self->field_04, on);
}
