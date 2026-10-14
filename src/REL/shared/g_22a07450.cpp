struct VObj {
    int field_0[5];
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void Update();
};

struct Entry {
    VObj* obj;
    int field_4;
};

struct List {
    int field_0;
    int field_4;
    Entry* items;
    unsigned int count;
};

extern "C" void shared_g_22a07450(List* self) {
    for (unsigned int i = 0; i < self->count; i++) {
        self->items[i].obj->Update();
    }
}
