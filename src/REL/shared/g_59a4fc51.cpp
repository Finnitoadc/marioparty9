struct Child {
    char pad0[0x14];
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03(void* p);
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12(void* p);
    int field_18;
    int field_1c;
    void* field_20;
};

struct Obj {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    char* field_10;
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    Child* field_28;
};

extern "C" void shared_g_59a4fc51(Obj* self, Child* c) {
    if (self->field_28 == 0) {
        self->field_28 = c;
        c->field_20 = self;
        self->field_28->v03(self->field_10 + 0x10);
        self->field_28->v12(self);
        self->v15();
    }
}
