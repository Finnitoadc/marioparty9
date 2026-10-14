extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80046040(void* res, int flags);

struct Elem {
    virtual ~Elem();
    int field_4;
};

struct Array {
    Elem* data;
    unsigned int count;

    Elem* Begin() { return data; }
    Elem* End() { return data + count; }
    static void Destroy(Elem* last, int n) {
        for (; n != 0; --n) {
            (--last)->~Elem();
        }
    }
    void Erase(Elem* first, int n) {
        Elem* last = first + n;
        count -= n;
        Destroy(last, n);
    }
    void Unused(Elem* last, int n) {
        while (n != 0) {
            --last;
            last->~Elem();
            --n;
        }
    }
    void Clear() { Erase(Begin(), count); }
    void Free() {
        if (data != 0) {
            Clear();
            fn_8020B5FC(data);
        }
    }
};

struct Res {
    void* p;
};

struct Obj {
    int field_0;
    Res res;
    Array arr;
};

extern "C" Obj* shared_g_093c28ca(Obj* self, int del) {
    if (self != 0) {
        Array* a = &self->arr;
        if (a != 0) {
            if (a != 0) {
                if (a != 0) {
                    if (a->data != 0) {
                        Elem* last;
                        unsigned int n;
                        n = a->count;
                        Elem* first = a->data;
                        a->count -= n;
                        last = first + n;
                        for (; n != 0; --n) {
                            (--last)->~Elem();
                        }
                        fn_8020B5FC(a->data);
                    }
                }
            }
        }
        Res* r = &self->res;
        if (r != 0) {
            fn_80046040(r->p, 1);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
