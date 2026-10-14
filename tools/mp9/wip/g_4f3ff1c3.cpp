template <typename T>
static inline void Swap(T& a, T& b) { T t = a; a = b; b = t; }
struct Less { bool operator()(const int& a, const int& b) const { return a < b; } };
extern "C" void shared_g_4f3ff1c3(int*& x, int*& y, int*& z) {
    Less comp;
    bool c1 = !comp(*z, *x);
    bool c2 = !comp(*y, *z);
    if (c1 && c2) {
        return;
    }
    if (!c1 && !c2) {
        Swap(*x, *y);
        return;
    }
    if (comp(*y, *x)) {
        Swap(*x, *y);
    }
    if (c1) {
        Swap(*y, *z);
    } else {
        Swap(*x, *z);
    }
}
