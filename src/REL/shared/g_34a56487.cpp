struct Obj {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
};

extern "C" unsigned int lbl_8026E2A4;
extern "C" void fn_80071590();
extern "C" int fn_80074EA0();

extern "C" void shared_g_34a56487(Obj* self) {
    while (!(lbl_8026E2A4 & 0x100) || !fn_80074EA0()) {
        self->v05();
        fn_80071590();
    }
}
