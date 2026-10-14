struct Vec {
    float x, y, z;
};

struct Sub {
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
};

extern "C" void fn_800600E0(Sub* s, Vec* v);

struct Obj {
    char pad0[0x68];
    Sub field_68;
    char pad6c[0x620 - 0x6C];
    Vec field_620;
    char pad62c[0x77C - 0x62C];
    float field_77c;
};

extern "C" void shared_g_3c1f615e(Obj* self) {
    Vec v = self->field_620;
    v.y += self->field_77c;
    fn_800600E0(&self->field_68, &v);
    self->field_68.v14();
}
