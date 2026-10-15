struct Item {
    int state;
    char pad[0x10];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(int a, int b);
    char pad2[0x14];
    int field_2C;
};

struct Entry {
    Item* item;
    int extra;
};

struct Obj {
    char pad[8];
    Entry* items;
    unsigned count;
};

extern "C" void shared_g_2215b64c(Obj* self, int arg) {
    for (unsigned i = 0; i < self->count; i++) {
        Item* it = self->items[i].item;
        bool b = it->state > 1 && it->state < 6;
        if (b) {
            it->v12(arg, it->field_2C);
        }
    }
}
