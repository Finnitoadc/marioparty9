struct Sub {
    int field_0;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int);
};

struct Obj {
    int pad[10];
    Sub sub;
};

extern "C" int shared_g_76e25039(void*);

extern "C" void shared_g_8c5d226d(Obj* self) {
    if (shared_g_76e25039(&self->sub)) {
        self->sub.v3(0);
    }
}
