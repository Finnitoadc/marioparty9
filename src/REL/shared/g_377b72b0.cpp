struct VObj {
    int field_0[5];
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
    virtual void Run(int a);
};

struct Slot {
    char pad[0x28];
    VObj* obj;
};

struct Obj {
    int field_0;
    int field_4;
    int field_8;
    Slot** slots;
};

extern "C" void shared_g_377b72b0(Obj* self, int i, int a) {
    VObj* p = self->slots[i]->obj;
    if (p) {
        p->Run(a);
    }
}
