extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80046040(void* p, int v);
extern "C" void fn_80071420(void* p, int v);

struct Elem {
    virtual void dtor(int del);
    int field_4;
};

struct Array {
    char* data;
    int count;

        char* BeginC() { return data; }
    char* EndC() { return data + count; }
    void Erase(char* first, char* last) { count -= last - first; }
    void Clear() { Erase(BeginC(), EndC()); }
    void Free() {
        if (data != 0) {
            Elem* p = (Elem*)data + count;
            int n = count;
            Clear();
            for (; n != 0; n--) {
                p--;
                p->dtor(-1);
            }
            fn_8020B5FC(data);
        }
    }
};

struct Obj {
    char pad[8];
    char field_8[8];
    Array arr;
};

extern "C" Obj* shared_g_99966faf(Obj* self, int del) {
    if (self != 0) {
        Array* a = &self->arr;
        if (a != 0) {
            if (a != 0) {
                if (a != 0) {
                    a->Free();
                }
            }
        }
        fn_80046040(self->field_8, 0);
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
