extern "C" int fn_8021053C(const char* a, const char* b, unsigned n);

struct Str {
    unsigned isLong : 1;
    unsigned len : 7;
    int lsize;
    char* lptr;

    unsigned Size() const {
        unsigned r; if (!isLong) r = *(const unsigned char*)this & 0x7F; else r = lsize; return r;
    }
    const char* Data() const {
        if (isLong) return lptr;
        return (const char*)this + 1;
    }
};

template <class T> inline const T& Min(const T& a, const T& b) { return b < a ? b : a; }

static inline int Compare(const Str* a, const Str* b) {
    unsigned lb = b->Size();
    const char* pb = b->Data();
    unsigned la = a->Size();
    unsigned n = Min(Min(la, a->Size()), lb);
    int r = fn_8021053C(a->Data(), pb, n);
    if (r != 0) return r;
    if (n < lb) return -1;
    if (n != lb) return 1;
    return 0;
}

extern "C" int shared_g_cde9e11b(const Str* a, const Str* b) {
    return !(a->Size() == b->Size() && Compare(a, b) == 0);
}
