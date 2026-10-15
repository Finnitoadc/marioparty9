struct Vec { float x, y, z; };
extern "C" float lbl_8026DAB4;

struct Node { char pad[0x2c]; Vec v; };
struct Mgr {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual Node* v13(int a, int b);
};
extern "C" Mgr* fn_800486E0();

static inline void scale(Vec* o, const Vec& v) {
    o->z = v.z;
    o->y = v.y;
    o->x = v.x * lbl_8026DAB4;
}

extern "C" void shared_g_8a42e3fc(void* self, int a, Vec* out) {
    Node* n = fn_800486E0()->v13(a, 1);
    Vec v;
    v.x = n->v.x;
    v.y = n->v.y;
    v.z = n->v.z;
    scale(out, v);
}
