struct Target {
    int pad[9];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void f5(int x);
};
struct S { Target* field_0; };
extern "C" void shared_g_9f120784(S* self, Target* val) {
    Target* old = self->field_0;
    if (val == old) return;
    self->field_0 = val;
    if (old != 0) old->f5(1);
}
