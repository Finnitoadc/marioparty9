extern "C" void fn_8020B5FC(void*);

struct Buf {
    unsigned owned : 1;
    unsigned pad0 : 31;
    int field_4;
    void* data;
};

struct Pair {
    Buf a;
    Buf b;
};

extern "C" Pair* shared_g_ca968c6f(Pair* self, int del) {
    if (self != 0) {
        if (&self->b != 0) {
            if (self->b.owned) {
                fn_8020B5FC(self->b.data);
            }
        }
        Buf* a = &self->a;
        if (a != 0) {
            if (a->owned) {
                fn_8020B5FC(a->data);
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
