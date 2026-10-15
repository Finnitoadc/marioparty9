struct Vec {
    int x, y, z;
};
struct Cmp {
    int (*fn)(Vec*, Vec*);
};
static inline void swap(Vec* a, Vec* b) {
    int x = a->x;
    a->x = b->x;
    int y = a->y;
    a->y = b->y;
    int z = a->z;
    a->z = b->z;
    Vec t;
    t.x = x;
    t.y = y;
    t.z = z;
    Vec u = t;
    *b = u;
}
extern "C" void shared_g_833a5dea(Vec* a, Vec* b, Vec* c, Cmp* cmp) {
    int x = !cmp->fn(c, a);
    int y = !cmp->fn(b, c);
    if (x && y) return;
    if (!x && !y) {
        swap(a, b);
        return;
    }
    if (cmp->fn(b, a)) swap(a, b);
    if (x) swap(b, c);
    else swap(a, c);
}
