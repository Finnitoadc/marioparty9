struct S {
    int pad[5];
    int arr[1];
};
extern "C" int shared_g_2e6e4ef8(S* s, int i) {
    return s->arr[i];
}
