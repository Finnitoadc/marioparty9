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
    virtual void v11();
    virtual void v12();
    virtual int v13(float x);
};

struct Obj : VObj {
    char pad[0x1C];
    float field_20;
};

extern "C" int shared_g_17a45aea(Obj* self) {
    return self->v13(self->field_20);
}
