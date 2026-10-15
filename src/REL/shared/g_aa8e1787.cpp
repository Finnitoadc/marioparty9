struct Obj {
    int pad[4];
    virtual void v0();
    virtual void v1(int a);
};
extern "C" void shared_g_aa8e1787(Obj* self, int a, int b) { self->v1(b); }
