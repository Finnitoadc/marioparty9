struct Ring {
    int* data;
    unsigned start;
    unsigned count;
    unsigned cap;
};

struct Iter {
    int* cur;
    int* base;
    int* first;
    int* end;
};

static inline void Make(Iter* out, const Ring& r, unsigned idx) {
    int* base = r.data;
    int* first = base + r.start;
    int* end = base + r.cap;
    out->base = base;
    out->cur = base + idx;
    out->first = first;
    out->end = end;
}

extern "C" void shared_g_c53f8468(Iter* out, Ring* r) {
    unsigned idx = r->cap != 0 ? (r->start + r->count) % r->cap : 0;
    Make(out, *r, idx);
}
