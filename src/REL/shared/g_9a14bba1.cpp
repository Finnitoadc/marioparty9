extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80086F10(void* p, int v);
extern "C" void fn_80071420(void* p, int v);
extern "C" void fn_8005CE40(void* p, int v);

struct Child {
    virtual void dtor(int del);
};

struct Sub {
    int field_0;
    char field_4[4];
};

struct Holder {
    Child* ptr;
};

struct Obj {
    char pad[0x148];
    char field_148[8];
    Sub sub;
    char pad2[0xAC];
    Holder h;
};

extern "C" Obj* shared_g_9a14bba1(Obj* self, int del) {
    if (self != 0) {
        Holder* h = &self->h;
        if (h != 0) {
            Child* c = h->ptr;
            if (c != 0) {
                c->dtor(1);
            }
        }
        Sub* s = &self->sub;
        if (s != 0) {
            fn_80086F10(s->field_4, -1);
        }
        fn_80071420(self->field_148, 0);
        fn_8005CE40(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
