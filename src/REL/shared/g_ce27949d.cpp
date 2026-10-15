extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* obj, int flags);

struct Virt {
    virtual void dtor(int);
};

struct Holder {
    Virt* ptr;
};

struct Obj {
    char pad[0x14];
    Holder field_14;
};

extern "C" Obj* shared_g_ce27949d(Obj* self, int del) {
    if (self != 0) {
        Holder* h = &self->field_14;
        if (h != 0) {
            if (h->ptr != 0) {
                h->ptr->dtor(1);
            }
        }
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
