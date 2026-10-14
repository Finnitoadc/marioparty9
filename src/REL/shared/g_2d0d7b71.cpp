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
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void Run();
};

struct Obj {
    char pad[0x238];
    Sub sub;
    char pad2[0x570];
    int field_7ac;
};

extern "C" void shared_g_2d0d7b71(Obj* self, int v) {
    self->field_7ac = v;
    self->sub.Run();
}
