struct R { int a; int cnt; };
struct P { int a; R* r; };
extern "C" P* shared_g_c65e3b01(P* d, P* s) {
    R* r = s->r;
    int a = s->a;
    d->a = a;
    d->r = r;
    if (r != 0) r->cnt++;
    return d;
}
