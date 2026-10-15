struct Obj {
    int pad[2];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
};

extern "C" void shared_g_aa2810d3(Obj* self, int a, int b, int c) {
    if (c) self->v10();
    if (b) self->v9();
    if (c) self->v10();
    if (a) self->v11();
}
