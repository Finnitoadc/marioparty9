struct Rect {
    float a, b, c, d;
};

extern "C" int shared_g_c170763e(Rect* r, Rect* p) {
    int res = 0;
    if (p->a >= r->a && p->c < r->c && p->b >= r->b && p->d < r->d) {
        res = 1;
    }
    return res;
}
