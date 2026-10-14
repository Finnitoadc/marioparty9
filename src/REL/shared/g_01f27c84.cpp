struct Obj {
    int state;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04(int x);
};

extern "C" void shared_g_01f27c84(Obj* self) {
    self->v04(1);
    self->state = 3;
}
