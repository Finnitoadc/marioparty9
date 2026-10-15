struct P { int a, b, c; };
struct Q { int a, b; };
extern "C" void shared_g_a028158b(Q* dst, P a, P b) {
    dst->a = a.a;
    dst->b = b.a;
}
