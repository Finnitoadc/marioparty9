struct Target {
    int field_0;
    int field_4;
    int field_8;
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04(int x);
};

struct Obj {
    Target* field_0;
};

extern "C" void shared_g_30b68bd2(Obj* self, Target* t) {
    Target* old = self->field_0;
    if (t == old) {
        return;
    }
    self->field_0 = t;
    if (old != 0) {
        old->v04(1);
    }
}
