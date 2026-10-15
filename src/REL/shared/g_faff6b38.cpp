struct R { char pad[0xbb]; unsigned char flags; };
struct M {
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
    virtual R* get(int a, int b);
};
extern "C" M* fn_800486E0();
extern "C" void shared_g_faff6b38(int self, int a, int on) {
    R* r = fn_800486E0()->get(a, 1);
    r->flags = (r->flags & 0xFE) | (unsigned char)on;
}
