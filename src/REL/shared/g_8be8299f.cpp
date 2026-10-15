extern "C" void fn_8020B5FC(void* ptr);

struct Str {
    unsigned flags;
    int pad;
    void* data;
};

static inline void Free(Str* s) {
    if (s != 0) {
        if (s->flags >> 31) {
            fn_8020B5FC(s->data);
        }
    }
}

struct Obj {
    int pad;
    Str a;
    Str b;
    Str c;
};

extern "C" Obj* shared_g_8be8299f(Obj* self, int del) {
    if (self != 0) {
        Free(&self->c);
        Free(&self->b);
        Free(&self->a);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
