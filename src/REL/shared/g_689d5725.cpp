struct Item {
    int field_0;
    char pad[0x10];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int n);
    virtual void v9();
    virtual void v10();
    virtual void v11(int x, int y);
    virtual void v12(int a, int b);
};

struct Entry {
    Item* item;
    int field_4;
};

struct List {
    char pad[0x8];
    Entry* data;
    unsigned int count;
};

static inline void Run(Item* it, int x, int y, int a, int b) {
    it->v11(x, y);
    it->v12(a, b);
    it->v8(0);
}

extern "C" int shared_g_689d5725(List* self, int x, int y, int a, int b) {
    Item* it;
    unsigned int i;
    for (i = 0; i < self->count; i++) {
        it = self->data[i].item;
        if (it->field_0 == 1 || it->field_0 == 6) {
            Run(it, x, y, a, b);

            return i;
        }
    }
    return -1;
}
