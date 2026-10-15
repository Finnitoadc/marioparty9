extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80041460(void* p, int v);
extern "C" void fn_80071420(void* p, int v);
extern "C" void fn_8005CE40(void* p, int v);

struct Inner {
    char pad[0x14];
    char field_14[4];
};

struct Holder {
    Inner* ptr;
};

struct Obj {
    char pad[0x148];
    char field_148[8];
    Holder h;
};

extern "C" Obj* shared_g_9ae0b1ad(Obj* self, int del) {
    if (self != 0) {
        Holder* h = &self->h;
        if (h != 0) {
            Inner* p = h->ptr;
            if (p != 0) {
                fn_80041460(p->field_14, -1);
                fn_8020B5FC(p);
            }
        }
        fn_80071420(self->field_148, 0);
        if (self != 0) {
            fn_8005CE40(self, 0);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
