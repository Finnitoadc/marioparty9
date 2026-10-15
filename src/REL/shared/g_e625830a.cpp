struct Inner {
    char pad[0x94];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
};
struct Obj {
    Inner* field_0;
};
extern "C" void shared_g_e625830a(Obj* self, Inner* p) {
    Inner* old = self->field_0;
    if (p == old) return;
    self->field_0 = p;
    if (old == 0) return;
    old->v5(1);
}
