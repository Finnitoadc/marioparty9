struct Cur {
    int* p;
};
typedef int (*Rnd)(int);
static inline void Swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
extern "C" void shared_g_d2aea873(Cur* a, Cur* b, Rnd rnd) {
    int n = b->p - a->p;
    if (n > 1) {
        b->p--;
        for (; a->p < b->p; a->p++) {
            Swap(a->p, a->p + rnd(n--));
        }
    }
}
