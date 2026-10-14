extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* obj, int flags);
extern "C" void fn_80086F10(void* obj, int flags);
extern "C" void fn_80046040(void* obj, int flags);
extern "C" void fn_8020BCD0(void* arr, void* dtor, int size, int n);
extern "C" void shared_g_83da6437();

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

struct Inner {
    Handle handle;
    Ptr ptr8;
    Ptr ptrC;
    char arr[8];
};

struct Res {
    void* p;
};

struct Obj {
    char pad[0x1C];
    Res res;
    char pad2[0xC];
    Inner* inner;
    Handle h30;
    Handle h38;
};

extern "C" Obj* shared_g_7c1232aa(Obj* self, int del) {
    if (self != 0) {
        Handle* h = &self->h38;
        if (h != 0) {
            fn_80086F10(h->obj, -1);
        }
        h = &self->h30;
        if (h != 0) {
            fn_80086F10(h->obj, -1);
        }
        Inner** pi = &self->inner;
        if (pi != 0) {
            Inner* in = *pi;
            if (in != 0) {
                fn_8020BCD0(in->arr, (void*)shared_g_83da6437, 4, 2);
                Ptr* p = &in->ptrC;
                if (p != 0) {
                    delete p->p;
                }
                p = &in->ptr8;
                if (p != 0) {
                    delete p->p;
                }
                Handle* ih = &in->handle;
                if (ih != 0) {
                    fn_80086F10(ih->obj, -1);
                }
                fn_8020B5FC(in);
            }
        }
        Res* r = &self->res;
        if (r != 0) {
            fn_80046040(r->p, 1);
        }
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
