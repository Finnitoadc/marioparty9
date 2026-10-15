struct O { virtual void v0(); virtual void v1(); };
extern "C" void fn_80060100();
extern "C" void shared_g_c90b2918(O* o) {
    o->v1();
    fn_80060100();
}
