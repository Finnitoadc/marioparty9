struct Child {
    char pad[0x70];
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C(int x);
};

struct Obj {
    Child* field_0;
};

extern "C" void shared_g_bd72779b(Obj* self, Child* c) {
    Child* old = self->field_0;
    if (c == old) {
        return;
    }
    self->field_0 = c;
    if (old != 0) {
        old->v01C(1);
    }
}
