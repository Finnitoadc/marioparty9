extern "C" void fn_8020B5FC(void* ptr);

struct Obj {
    virtual void v0(int);
};

struct Hold {
    Obj* p;
};

struct S {
    char pad[0x40];
    Hold field_40;
};

extern "C" S* shared_g_e5133eda(S* self, int del) {
    if (self != 0) {
        Hold* h = &self->field_40;
        if (h != 0) {
            Obj* o = h->p;
            if (o != 0) {
                o->v0(1);
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
