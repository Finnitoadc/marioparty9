extern "C" void* memmove(void* d, const void* s, unsigned n);
struct V { int* data; int count; };
extern "C" int* shared_g_a3b6d6c2(V* v, int** it) {
    int* p = *it;
    memmove(p, p + 1, (v->data + v->count - p - 1) * 4);
    v->count--;
    return p;
}
