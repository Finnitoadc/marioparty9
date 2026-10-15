struct O {
    int pad[4];
    virtual void v0();
    virtual void v1();
    virtual void f(int a);
};

extern "C" void shared_g_5f2c3dc3(O* self, int a, int b) {
    self->f(b);
}
