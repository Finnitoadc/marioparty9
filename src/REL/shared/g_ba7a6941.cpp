extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* self, int flags);

struct Base {
    int field_0;
};

struct VObj : Base {
    virtual void Dtor(int del);
};

struct Flags {
    unsigned int flags;
    int field_4;
    void* buf;
};

struct Owner {
    int field_0;
    int field_4;
    VObj* obj;
    int field_c;
    Flags f;
};

extern "C" Owner* shared_g_ba7a6941(Owner* self, int del) {
    if (self != 0) {
        if (&self->f != 0) {
            if ((self->f.flags >> 31) != 0) {
                fn_8020B5FC(self->f.buf);
            }
        }
        VObj** objAddr = &self->obj;
        if (objAddr != 0) {
            VObj* obj = *objAddr;
            if (obj != 0) {
                obj->Dtor(1);
            }
        }
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
