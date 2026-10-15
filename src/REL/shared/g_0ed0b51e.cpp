struct Obj {
    int pad;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int);
};
extern "C" void fn_80071590();
extern "C" int shared_g_c28ef4b7(Obj*);
extern "C" void shared_g_0ed0b51e(Obj* self) {
    self->v3(1);
    while (!shared_g_c28ef4b7(self)) {
        fn_80071590();
    }
}
