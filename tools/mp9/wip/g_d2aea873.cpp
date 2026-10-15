struct Cur {
    int* p;
};
typedef int (*Rnd)(int);
extern "C" void shared_g_d2aea873(Cur* a, Cur* b, Rnd rnd) {
    int n = b->p - a->p;
    if (n > 1) {
        b->p--;
        while (a->p < b->p) {
            int r = rnd(n);
            n--;
            int t = a->p[0];
            int* q = a->p + r;
            a->p[0] = *q;
            *q = t;
            a->p++;
        }
    }
}
