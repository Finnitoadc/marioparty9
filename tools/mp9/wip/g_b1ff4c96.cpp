extern "C" void* memmove(void* dst, const void* src, unsigned n);

struct Iter {
    int* cur;
    int* first;
    int* last;
    int** node;

    void Dec() {
        if (cur == first) {
            cur = (int*)node;
        }
        cur--;
    }
    int* Base() {
        return (cur >= last) ? last : first;
    }
    int Off() {
        return cur - Base();
    }
};

static inline const int& imin(const int& a, const int& b) {
    return (a < b) ? a : b;
}

extern "C" Iter shared_g_b1ff4c96(Iter a, Iter b, Iter c) {
    while (a.cur != b.cur) {
        b.Dec();
        c.Dec();
        int n1 = c.Off();
        int k;
        if (b.cur >= b.last == a.cur >= a.last) {
            int n2 = b.cur - a.cur;
            k = imin(n1, n2);
        } else {
            int n2 = b.Off();
            k = imin(n1, n2);
        }
        b.cur -= k;
        int n = (b.cur + (k + 1)) - b.cur;
        memmove(c.cur + 1 - n, b.cur, n * 4);
        c.cur -= k;
    }
    return c;
}
