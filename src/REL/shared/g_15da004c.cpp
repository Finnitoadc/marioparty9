extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80099710(void* p, int a);
extern "C" void fn_80071420(void* p, int a);

struct V {
    virtual ~V();
};

struct Holder {
    V* p;
};

struct Obj {
    char pad[8];
    char m8[0x18];
    Holder m20;
};

extern "C" Obj* shared_g_15da004c(Obj* self, int del) {
    if (self != 0) {
        Holder* h = &self->m20;
        if (h != 0) {
            delete h->p;
        }
        fn_80099710(&self->m8, 0);
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
