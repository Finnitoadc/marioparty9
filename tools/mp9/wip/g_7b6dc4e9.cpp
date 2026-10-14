extern "C" void* memmove(void* dst, const void* src, unsigned long n);

struct It {
    int* cur;
    int* begin;
    int* start;
    int* end;
    It(It& o) : cur(o.cur), begin(o.begin), start(o.start), end(o.end) {}
    bool Wrapped() const { return cur >= start; }
};

static inline int* CopyPtr(int* f, int* l, int* d) {
    unsigned long n = l - f;
    memmove(d, f, n * sizeof(int));
    return d + n;
}

static inline const int& Min(const int& a, const int& b) { return a < b ? a : b; }

extern "C" It shared_g_7b6dc4e9(It& first, It& last, It& dest) {
    while (first.cur != last.cur) {
        int n = dest.end - dest.cur;
        int count;
        if (first.Wrapped() == last.Wrapped()) {
            count = Min(n, (int)(last.cur - first.cur));
        } else {
            count = Min(n, (int)(first.end - first.cur));
        }
        CopyPtr(first.cur, first.cur + count, dest.cur);
        first.cur += count - 1;
        if (++first.cur == first.end) {
            first.cur = first.begin;
        }
        dest.cur += count - 1;
        if (++dest.cur == dest.end) {
            dest.cur = dest.begin;
        }
    }
    return dest;
}
