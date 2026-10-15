extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* obj, int flags);
extern "C" void fn_80086F10(void* obj, int flags);

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

struct Virt {
    char pad[4];
    virtual void dtor(int);
};

struct Holder {
    Virt* ptr;
};

struct Holder2 {
    void* ptr;
};

struct Obj {
    char pad[0xc];
    Holder hc;
    Holder2 h10;
    Buffer b14;
    int padx;
    Buffer b20;
    char pad2[0x18];
    char field_40[4];
};

extern "C" Obj* shared_g_fb52857e(Obj* self, int del) {
    if (self != 0) {
        fn_80086F10(self->field_40, -1);
        Buffer* b = &self->b20;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    b->Free();
                }
            }
        }
        b = &self->b14;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b != 0) {
                        b->Free();
                    }
                }
            }
        }
        Holder2* h = &self->h10;
        if (h != 0) {
            fn_8020B5FC(h->ptr);
        }
        Holder* c = &self->hc;
        if (c != 0) {
            if (c->ptr != 0) {
                c->ptr->dtor(1);
            }
        }
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
