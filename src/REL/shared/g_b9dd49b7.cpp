extern "C" void fn_8020B5FC(void*);

struct Buf {
    unsigned owned : 1;
    unsigned pad1 : 31;
    int field_4;
    void* data;
};

struct Obj {
    int field_0;
    Buf b;
};

extern "C" Obj* shared_g_b9dd49b7(Obj* self, int del) {
    if (self != 0) {
        if (&self->b != 0) {
            if (self->b.owned) {
                fn_8020B5FC(self->b.data);
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
