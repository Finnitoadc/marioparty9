struct E {
    int pad[7];
};
struct S {
    E* data;
};
extern "C" E* shared_g_bb4d80a1(S* s, int i) {
    return &s->data[i];
}
