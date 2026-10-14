struct Iter {
    int* p;
};

extern "C" int* shared_g_5e407b2e(Iter* it) {
    int* r = it->p;
    it->p = r + 1;
    return r;
}
