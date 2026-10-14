extern "C" void fn_8020B5FC(void* p);
extern "C" void fn_8002AE40(void* p, int a);
extern "C" void fn_8009ACF0(void* p);
extern "C" void fn_80046040(void* self, int del);

struct VElem {
    virtual void Destroy(int del);
    int field_4;
};

struct Ref {
    int field_0;
    void* p;
};

struct Elem {
    char pad[0xC];
    Ref ref;
};

static inline void DestroyElem(Elem* e) {
    if (e != 0) {
        Ref* r = &e->ref;
        if (r != 0) {
            if (r->p != 0) {
                fn_8009ACF0(r->p);
            }
        }
    }
}

struct EBuffer {
    Elem* data;
    int count;

    static void DestroyBack(Elem* p, int n) {
        while (n != 0) {
            --p;
            DestroyElem(p);
            n--;
        }
    }
    void Erase(int start, int n) {
        Elem* p = data + start + n;
        count -= n;
        DestroyBack(p, n);
    }
    void Clear() { Erase(0, count); }
};

struct VBuffer {
    VElem* data;
    int count;

    static void DestroyBack(VElem* p, int n) {
        while (n != 0) {
            --p;
            p->Destroy(-1);
            n--;
        }
    }
    void Erase(int start, int n) {
        VElem* p = data + start + n;
        count -= n;
        DestroyBack(p, n);
    }
    void Clear() { Erase(0, count); }
};

struct Handle {
    void* p;
};

struct Obj {
    char pad[0x8];
    VBuffer vbuf;
    char pad10[0x4];
    EBuffer ebuf;
    char pad1c[0x4];
    Handle h;
};

extern "C" Obj* shared_g_462e0826(Obj* self, int del) {
    if (self != 0) {
        Handle* h = &self->h;
        if (h != 0) {
            fn_8002AE40(h->p, 1);
        }
        EBuffer* e = &self->ebuf;
        if (e != 0) {
            if (e != 0) {
                if (e != 0) {
                    if (e->data != 0) {
                        e->Clear();
                        fn_8020B5FC(e->data);
                    }
                }
            }
        }
        VBuffer* v = &self->vbuf;
        if (v != 0) {
            if (v != 0) {
                if (v != 0) {
                    if (v->data != 0) {
                        v->Clear();
                        fn_8020B5FC(v->data);
                    }
                }
            }
        }
        fn_80046040(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
