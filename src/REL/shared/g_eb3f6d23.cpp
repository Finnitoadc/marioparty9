struct Child {
    char pad[0xc0];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
};

struct Obj { Child* field_0; };

extern "C" void shared_g_eb3f6d23(Obj* self, Child* c) {
    Child* old = self->field_0;
    if (c == old) return;
    self->field_0 = c;
    if (old) {
        old->v5(1);
    }
}
