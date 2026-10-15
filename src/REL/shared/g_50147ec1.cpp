struct O { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); };
struct A { char pad[0x338]; O* field_338; };
extern "C" void shared_g_50147ec1(A* a) { a->field_338->v2(); }
