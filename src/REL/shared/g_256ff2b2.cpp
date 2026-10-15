struct O { virtual void v0(); virtual void v1(); virtual O* v2(); };
extern "C" void fn_80060220(O* o, int a);
extern "C" void shared_g_256ff2b2(O* o, int a) { fn_80060220(o->v2(), a); }
