struct Pair {
    int a;
    int b;
};

extern "C" void shared_g_1d3d817f(int a, int b) {
    volatile Pair p;
    p.a = a;
    p.b = b;
}
