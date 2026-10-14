struct Item {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03(int a, int b);
};

struct Obj {
    int field_0;
    int field_4;
    Item** field_8;
    int field_c;
};

extern "C" void shared_g_0c6519fb(Obj* self) {
    for (Item** p = self->field_8; p != self->field_8 + self->field_c; p++) {
        (*p)->v03(0, 1);
    }
}
