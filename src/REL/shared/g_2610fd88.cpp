extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80046040(void* res, int flags);
extern "C" void fn_80071420(void* self, int del);

struct Res {
    void* res;
};

struct Holder {
    Res* ptr;
};

struct Obj {
    char pad[0x1C];
    Holder holder;
};

static inline void DestroyRes(Res* r) {
    if (r != 0) {
        fn_80046040(r->res, 1);
    }
}

extern "C" Obj* shared_g_2610fd88(Obj* self, int del) {
    if (self != 0) {
        Holder* h = &self->holder;
        if (h != 0) {
            Res* r = h->ptr;
            if (r != 0) {
                DestroyRes(r);
                fn_8020B5FC(r);
            }
        }
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
