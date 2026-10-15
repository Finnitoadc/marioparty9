struct B { int pad[3]; int field_c; };
struct A { char pad[0x148]; B* field_148; };
extern "C" void shared_g_482b3e15(A* a, int v) { a->field_148->field_c = v; }
