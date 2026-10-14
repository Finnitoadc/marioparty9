struct VObj {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void* s10();
};

extern "C" void* shared_g_4314a11d(VObj* self) {
    return self->s10();
}
