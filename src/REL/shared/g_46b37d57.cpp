struct Item {
    virtual void v00(int del);
};

struct Ptr {
    Item* p;
};

struct Obj {
    int field_0;
    Ptr field_4;
};

extern "C" void fn_8020B5FC(void* p);

extern "C" Obj* shared_g_46b37d57(Obj* self, int del) {
    if (self != 0) {
        Ptr* p = &self->field_4;
        if (p != 0) {
            if (p->p != 0) {
                p->p->v00(1);
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
