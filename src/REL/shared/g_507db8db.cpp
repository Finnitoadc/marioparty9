struct Child {
    int pad[2];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Release(int a);
};

struct Obj {
    Child* field_0;
};

extern "C" void shared_g_507db8db(Obj* self, Child* c) {
    Child* old = self->field_0;
    if (c != old) {
        self->field_0 = c;
        if (old != 0) old->Release(1);
    }
}
