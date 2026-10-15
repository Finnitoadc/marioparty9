extern "C" void fn_800600E0(void* o, int a);
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void* v2();
};
extern "C" void shared_g_b1f89fe5(Obj* self, int a) {
    fn_800600E0(self->v2(), a);
}
