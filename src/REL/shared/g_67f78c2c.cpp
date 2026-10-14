struct Item {
    char pad[0x14];
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int a);
};

struct Obj {
    char pad[0xC];
    Item** items;
    unsigned int count;
    char pad2[0x4];
    Item* field_18;
    Item* field_1C;
    void CallAll() {
        for (unsigned int i = 0; i < count; i++) {
            items[i]->v08(0);
        }
    }
};

extern "C" void shared_g_67f78c2c(Obj* self) {
    if (self->field_18 != 0) {
        self->field_18->v08(0);
    }
    self->CallAll();
    if (self->field_1C != 0) {
        self->field_1C->v08(0);
    }
}
