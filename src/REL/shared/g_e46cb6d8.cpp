extern "C" void fn_8020B5FC(void*);
extern "C" void fn_80086F10(void* obj, int flags);
extern "C" void fn_8005CE40(void* self, int flags);
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
struct Obj {
    char pad[0x148];
    Handle handle;
    Ptr ptr;
};
extern "C" Obj* shared_g_e46cb6d8(Obj* self, int del) {
    if (self != 0) {
        Ptr* p = &self->ptr;
        if (p != 0) {
            delete p->p;
        }
        Handle* h = &self->handle;
        if (h != 0) {
            fn_80086F10(h->obj, -1);
        }
        fn_8005CE40(self, 0);
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
