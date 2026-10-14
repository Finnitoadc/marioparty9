struct Sub {
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void Run();
};

struct Obj {
    char pad[0x238];
    Sub sub;
};

extern "C" void shared_g_ca3000b3(Obj* self) {
    self->sub.Run();
}
