struct Elem {
    int field_0;
    int field_4;
};

struct Comp {
    int (*fn)(Elem* a, Elem* b);
};

static inline void IterSwap(Elem** a, Elem** b) { Elem* pa = *a; Elem* pb = *b; Elem tmp = *pa; *pa = *pb; *pb = tmp; }

extern "C" void shared_g_129c9ae5(Elem** a, Elem** b, Elem** c, Comp* comp) {
    int ca = !comp->fn(*c, *a);
    int cb = !comp->fn(*b, *c);
    if (ca) {
        if (cb) {
            return;
        }
    }
    if (!ca && !cb) {
        IterSwap(a, b);
        return;
    }
    if (comp->fn(*b, *a)) {
        IterSwap(a, b);
    }
    if (ca) {
        IterSwap(b, c);
    } else {
        IterSwap(a, c);
    }
}
