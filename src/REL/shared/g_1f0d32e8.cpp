struct B { int pad; int v; };
struct S { char pad[0x1c]; B* p; };
extern "C" int shared_g_1f0d32e8(S* self) { return self->p->v; }
