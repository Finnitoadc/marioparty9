struct Vec { float x, y, z; };
struct Q { float x, y, z, w; };
struct Out { int pad; Vec v; float w; };

extern "C" void shared_g_1d3969ec(Out* o, const Q* q) {
    Vec v;
    float z;
    float y;
    float x;
    x = q->x;
    y = q->y;
    z = q->z;
    v.x = x; v.y = y; v.z = z;
    o->v = v;
    o->w = -q->w;
}
