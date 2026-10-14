struct Elem {
    virtual void Destroy(int del);
    int field_4;
};

struct Buffer {
    Elem* data;
    int count;

    Elem* Begin() { return data; }
    Elem* End() { return data + count; }
    static void DestroyBack(Elem* p, int n) {
        while (n != 0) {
            --p;
            p->Destroy(-1);
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

extern "C" void fn_80046040(void* p, int a);

struct Handle {
    void* p;
    void Release() { fn_80046040(p, 1); }
};

struct Obj {
    char pad[0x8];
    Handle field_8;
    Buffer buf;
};

extern "C" void fn_8020B5FC(void* p);
extern "C" void fn_80046040(void* p, int a);
extern "C" void fn_80071420(Obj* self, int del);

extern "C" Obj* shared_g_006e3070(Obj* self, int del) {
    if (self != 0) {
        if (&self->buf != 0) {
            if (&self->buf != 0) {
                if (&self->buf != 0) {
                    Buffer* b = &self->buf;
                    if (b->data != 0) {
                        b->Clear();
                        fn_8020B5FC(b->data);
                    }
                }
            }
        }
        Handle* h = &self->field_8;
        if (h != 0) {
            h->Release();
        }
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
