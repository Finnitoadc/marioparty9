extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80046040(void* res, int flags);

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
    void EraseIdx(int first, int last) { count -= last - first; }
    void Clear() { Erase(Begin(), End()); }
    static void DestroyN(Elem* b, int n) {
        Elem* p = b + n;
        for (; n != 0; n--) {
            (--p)->~Elem();
        }
    }
    void Clear2() {
        int n = count;
        count -= n;
        DestroyN(data, n);
    }
    void D2() { if (this != 0) Free(); }
    void D1() { if (this != 0) D2(); }
    void Free() {
        if (data != 0) {
            Clear();
            fn_8020B5FC(data);
        }
    }
};

struct Holder {
    int field_00;
    Array arr;
};

extern "C" Holder* shared_g_490f61b3(Holder* self, int del) {
    if (self != 0) {
        Array* a = &self->arr;
        if (a != 0) {
            if (a != 0) {
                if (a != 0) {
                    if (a->data != 0) {
                        Elem* p;
                        int n = a->count;
                        p = a->data + n;
                        a->count -= n;
                        for (; n != 0; n--) {
                            (--p)->~Elem();
                        }
                        fn_8020B5FC(a->data);
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
