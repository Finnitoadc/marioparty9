struct S {
    int a;
    int b;
    int c;
    int d;
    int e;
};

extern "C" void shared_g_c90e17d8(S* dst, S src) {
    *dst = src;
}
