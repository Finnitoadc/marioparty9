extern "C" void fn_8020B5FC(void* p);

struct Inner {
    char pad[0x10];
    virtual void v0(int);
};

struct Obj {
    Inner* field_0;
};

extern "C" Obj* shared_g_968005d8(Obj* self, int del) {
    if (self != 0) {
        if (self->field_0 != 0) {
            self->field_0->v0(1);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
