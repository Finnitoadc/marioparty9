struct It { unsigned* field_0; };
static inline bool ne(const It& x, const It& y) { return x.field_0 != y.field_0; }
extern "C" int shared_g_7d709974(It* a, It* b) {
    return ne(*a, *b);
}
