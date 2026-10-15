struct B { char pad[0x318]; unsigned char field_318; };
struct A { char pad[0x328]; B* field_328; };
extern "C" unsigned char shared_g_29fee67b(A* a) { return a->field_328->field_318; }
