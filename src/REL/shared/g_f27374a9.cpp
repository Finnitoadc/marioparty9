struct Col { unsigned char r, g, b, a; };
extern "C" Col* fn_80177B60();

extern "C" void shared_g_f27374a9(void* unused, Col* c) {
    Col* d = fn_80177B60();
    d->r = c->r;
    d->g = c->g;
    d->b = c->b;
    d->a = c->a;
}
