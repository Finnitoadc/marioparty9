// scheduling only: target interleaves loads of next column with stores of previous (f2,f1,f0 reuse)
struct M { float m[3][4]; };
static inline void put(float* d, float z, float y, float x) { d[0] = x; d[1] = y; d[2] = z; }
extern "C" void shared_g_5a6ad1cf(float* a, float* b, float* c, M* m) {
    put(a, m->m[2][0], m->m[1][0], m->m[0][0]);
    put(b, m->m[2][1], m->m[1][1], m->m[0][1]);
    put(c, m->m[2][2], m->m[1][2], m->m[0][2]);
}
