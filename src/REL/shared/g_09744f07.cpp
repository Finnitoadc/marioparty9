struct Vec {
    float x, y, z;
};

extern "C" Vec* fn_8004D180(Vec* out);

struct Obj {
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
    virtual void v16();
    virtual void v17(Vec* v);
};

extern "C" void shared_g_09744f07(Obj* self) {
    Vec tmp;
    self->v17(fn_8004D180(&tmp));
}
