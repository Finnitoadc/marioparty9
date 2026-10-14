// 2 diffs: slwi/subf swapped in the inlined vector clear
extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* obj, int flags);
extern "C" void fn_80086F10(void* obj, int flags);
extern "C" void fn_80046040(void* obj, int flags);

struct Elem {
    virtual ~Elem();
    int field_04;
};

struct Array {
    Elem* data;
    int count;

    Elem* Begin() { return data; }
    Elem* End() { return data + count; }
    void Erase(Elem* first, Elem* last) {
        int n = count;
        count -= n;
        for (; n != 0; n--) {
            (--last)->~Elem();
        }
    }
    void Clear() { Erase(Begin(), End()); }
    void Free() {
        if (data != 0) {
            Clear();
            fn_8020B5FC(data);
        }
    }
};

struct Handle {
    int field_0;
    char obj[4];
};

struct Obj {
    char pad[0x4];
    char field_4[0x8];
    Handle handle;
    Array arr;
};

extern "C" Obj* shared_g_085a5cf8(Obj* self, int del) {
    if (self != 0) {
        Array* a = &self->arr;
        if (a != 0) {
            if (a != 0) {
                if (a != 0) {
                    if (a->data != 0) {
                        Elem* p = a->data + a->count;
                        int n = a->count;
                        a->count -= n;
                        for (; n != 0; n--) {
                            (--p)->~Elem();
                        }
                        fn_8020B5FC(a->data);
                    }
                }
            }
        }
        Handle* h = &self->handle;
        if (h != 0) {
            fn_80086F10(h->obj, -1);
        }
        fn_80071420(self->field_4, 0);
        fn_80046040(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
