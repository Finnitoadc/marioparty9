struct T {
    char pad[0x150];
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void f(int a);
};
struct O { T* field_0; };

extern "C" void shared_g_60f3e81e(O* self, T* n) {
    if (n == self->field_0) return;
    T* old = self->field_0;
    self->field_0 = n;
    if (old) old->f(1);
}
