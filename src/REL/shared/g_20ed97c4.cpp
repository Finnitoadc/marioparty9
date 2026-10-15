struct S { int a, b, c; };
extern "C" void shared_g_20ed97c4(S* x, S* y) {
    int t = x->c; x->c = y->c; y->c = t;
    t = x->a; x->a = y->a; y->a = t;
    t = x->b; x->b = y->b; y->b = t;
}
