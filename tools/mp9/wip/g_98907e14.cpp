struct Elem {
    int field_00;
    void* ptr;
};
struct Vec {
    Elem* data;
    int count;
};
extern "C" void fn_8009ACF0(void*);
extern "C" void shared_g_98907e14(Vec* v) {
    Elem* e;
    int n = v->count;
    e = v->data + v->count;
    v->count -= n;
    for (; n != 0; n--) {
        e--;
        if (e != 0) {
            if (e->ptr != 0) fn_8009ACF0(e->ptr);
        }
    }
}
