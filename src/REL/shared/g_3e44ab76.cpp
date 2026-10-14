extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* obj, int flags);
extern "C" void fn_80086F10(void* obj, int flags);
extern "C" void fn_8005CE40(void* self, int flags);
extern "C" void fn_8003F020(void* obj, int flags);

struct Elem {
    virtual ~Elem();
};

struct Ptr {
    Elem* p;
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

struct Res {
    void* p;
};

struct Inner {
    char pad[0x8];
    char field_8[0x14C];
    OwnBuf buf;
    char pad2[0x8];
    Handle h168;
    Handle h170;
    Handle h178;
    char pad3[0x64];
    Res res;
    char pad4[0x24];
    Ptr ptr20c;
    char pad5[0x18];
    Ptr ptr228;
};

extern "C" Inner* shared_g_3e44ab76(Inner* self, int del) {
    if (self != 0) {
        Inner* in = self;
        if (in != 0) {
            Ptr* p = &in->ptr228;
            if (p != 0) {
                delete p->p;
            }
            p = &in->ptr20c;
            if (p != 0) {
                delete p->p;
            }
            Res* r = &in->res;
            if (r != 0) {
                fn_8003F020(r->p, 1);
            }
            Handle* h = &in->h178;
            if (h != 0) {
                fn_80086F10(h->obj, -1);
            }
            h = &in->h170;
            if (h != 0) {
                fn_80086F10(h->obj, -1);
            }
            h = &in->h168;
            if (h != 0) {
                fn_80086F10(h->obj, -1);
            }
            if (&in->buf != 0) {
                if (in->buf.flags >> 31) {
                    fn_8020B5FC(in->buf.data);
                }
            }
            fn_8005CE40(in->field_8, 0);
            fn_80071420(in, 0);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
