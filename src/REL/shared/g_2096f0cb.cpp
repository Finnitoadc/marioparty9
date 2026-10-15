struct V { float x, y, z; };
struct A { char pad[0x14]; V v; };
static inline void cp(V* d, const V& s) {
    float x = s.x, y = s.y, z = s.z;
    d->x = x; d->y = y; d->z = z;
}
extern "C" V* shared_g_2096f0cb(A* a, V* out) { cp(out, a->v); return out; }
