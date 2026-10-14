struct Vec {
    float x, y, z;
};

struct Obj {
    int field_0[5];
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void Set(Vec* v, int a);
};

extern "C" void shared_g_d97f9cae(Obj* self, int a, float x, float y, float z) {
    Vec v;
    v.x = x;
    v.y = y;
    v.z = z;
    self->Set(&v, a);
}
