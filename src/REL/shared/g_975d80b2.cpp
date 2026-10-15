struct E { int a, b, c; };
struct T { short pad0; unsigned short count; int pad[2]; E* data; };
struct R { T* t; E* e; };
struct Q { char pad[0x2878]; T t; };
extern "C" Q* fn_80052990();
static inline void set(R* out, T* t, E* e) { out->t = t; out->e = e; }
extern "C" void shared_g_975d80b2(R* out, void* a, int i) {
    Q* q = fn_80052990();
    unsigned n = q->t.count;
    T* t = &q->t;
    if (i < (int)n && i >= 0) {
        set(out, t, &t->data[i]);
    } else {
        set(out, t, 0);
    }
}
