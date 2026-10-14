struct Vec {
    float x, y, z;
};

struct Rect {
    float minX, minZ, maxX, maxZ;
};

static inline const float& Min(const float& a, const float& b) { return b < a ? b : a; }
static inline const float& Max(const float& a, const float& b) { return a < b ? b : a; }

extern "C" Rect* shared_g_585af956(void* self, const Vec* a, const Vec* b, const Vec* c, Rect* out) {
    out->minX = Min(a->x, Min(b->x, c->x));
    out->maxX = Max(a->x, Max(b->x, c->x));
    out->minZ = Min(a->z, Min(b->z, c->z));
    out->maxZ = Max(a->z, Max(b->z, c->z));
    return out;
}
