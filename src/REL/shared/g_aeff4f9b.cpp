struct Obj {
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
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C(float* v);
};

extern "C" void shared_g_aeff4f9b(Obj* self, float a, float b, float c, float d) {
    float v[4];
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    self->v04C(v);
}
