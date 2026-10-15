extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* obj, int flags);
extern "C" void fn_8003F020(void* obj, int flags);
extern "C" void fn_80086F10(void* obj, int flags);
extern "C" void fn_8005CE40(void* obj, int flags);

struct Virt {
    virtual void dtor(int);
};

struct Holder {
    Virt* ptr;
};

struct Holder2 {
    void* ptr;
};

struct Handle {
    int field_0;
    char obj[4];
};

struct OwnBuf {
    unsigned int flags;
    int field_4;
    void* data;
};

struct Obj {
    char pad[8];
    char field_8[0x14c];
    OwnBuf buf154;
    char pad2[8];
    Handle h168;
    Handle h170;
    Handle h178;
    char pad3[0x64];
    Holder2 h1e4;
    char pad4[0x24];
    Holder h20c;
    char pad5[0x18];
    Holder h228;
};

extern "C" Obj* shared_g_fcbeda73(Obj* self, int del) {
    if (self != 0) {
        Holder* a = &self->h228;
        if (a != 0) {
            if (a->ptr != 0) {
                a->ptr->dtor(1);
            }
        }
        Holder* b = &self->h20c;
        if (b != 0) {
            if (b->ptr != 0) {
                b->ptr->dtor(1);
            }
        }
        Holder2* c = &self->h1e4;
        if (c != 0) {
            fn_8003F020(c->ptr, 1);
        }
        Handle* d = &self->h178;
        if (d != 0) {
            fn_80086F10(d->obj, -1);
        }
        d = &self->h170;
        if (d != 0) {
            fn_80086F10(d->obj, -1);
        }
        d = &self->h168;
        if (d != 0) {
            fn_80086F10(d->obj, -1);
        }
        if (&self->buf154 != 0) {
            if (self->buf154.flags >> 31) {
                fn_8020B5FC(self->buf154.data);
            }
        }
        fn_8005CE40(self->field_8, 0);
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
