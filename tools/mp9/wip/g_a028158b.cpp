struct P { int a, b; };
extern "C" void shared_g_a028158b(P* dst, P* a, P* b) {
    P t;
    t.a = a->a;
    t.b = b->a;
    *dst = t;
}
