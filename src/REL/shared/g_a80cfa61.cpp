struct VObj {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual int v11(float x);
};

struct Obj : VObj {
    char pad[0x1C];
    float field_20;
};

extern "C" int shared_g_a80cfa61(Obj* self) {
    return self->v11(self->field_20);
}
