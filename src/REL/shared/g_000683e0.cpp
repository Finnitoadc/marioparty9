struct C { virtual void f(int); };
struct O { char pad[0x10]; int f10; C* f14; };
extern "C" void shared_g_000683e0(O* o) { if (o->f14) o->f14->f(o->f10); }
