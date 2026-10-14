extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* obj, int flags);
extern "C" void fn_80086F10(void* obj, int flags);
extern "C" void fn_8005CE40(void* self, int flags);

struct Buffer {
    char* data;
    int count;

    char* Begin() { return data; }
    char* End() { return data + count; }
    void Erase(char* first, char* last) { count -= last - first; }
    void Clear() { Erase(Begin(), End()); }
    void Free() {
        if (data != 0) {
            Clear();
            fn_8020B5FC(data);
        }
    }
};

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
    char field_148[8];
    Handle handle;
    Ptr ptr;
    Buffer buf;
};

extern "C" Obj* shared_g_4f5406e4(Obj* self, int del) {
    if (self != 0) {
        Buffer* b = &self->buf;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b != 0) {
                        b->Free();
                    }
                }
            }
        }
        Ptr* p = &self->ptr;
        if (p != 0) {
            delete p->p;
        }
        Handle* h = &self->handle;
        if (h != 0) {
            fn_80086F10(h->obj, -1);
        }
        fn_80071420(&self->field_148, 0);
        fn_8005CE40(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
