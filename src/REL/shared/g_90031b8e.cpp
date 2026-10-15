extern "C" void fn_8020B5FC(void*);

struct Buf {
    unsigned owned : 1;
    unsigned pad0 : 31;
    int field_4;
    void* data;
};

struct Obj {
    Buf a;
    char pad[0x18];
    Buf b;
};

extern "C" Obj* shared_g_90031b8e(Obj* self, int del) {
    if (self != 0) {
        if (&self->b != 0) {
            if (self->b.owned) {
                fn_8020B5FC(self->b.data);
            }
        }
        if (self != 0) {
            if (self->a.owned) {
                fn_8020B5FC(self->a.data);
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
