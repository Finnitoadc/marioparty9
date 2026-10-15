struct S { int pad[4]; int a; int b; int c; int d; int e; int f; };
extern "C" void shared_g_bb491dd7(S* s) {
    int n = s->e;
    if (n != -1) {
        int z = 0;
        s->a = n;
        s->b = z;
        s->c = z;
        s->d = -1;
        s->e = -1;
    } else if (s->d != -1) {
        int z = 0;
        int m = s->a + 1;
        s->b = z;
        s->a = m;
        s->c = z;
        s->d = -1;
    } else {
        s->c = s->c + 1;
    }
    s->f = s->f + 1;
}
