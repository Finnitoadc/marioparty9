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
    virtual void Get(int a, float* center, float* half);
};

extern "C" void shared_g_042c20ba(Obj* self, int a, float* lo, float* hi) {
    float center;
    float half;
    self->Get(a, &center, &half);
    *lo = center - half;
    *hi = center + half;
}
