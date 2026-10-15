extern "C" void fn_8020B5FC(void*);
extern "C" void fn_80046040(void* obj, int flags);
extern "C" void fn_8020BCD0(void* arr, void* dtor, int size, int n);
extern "C" void shared_g_627244bb();

struct Elem {
    virtual ~Elem();
    int field_4;
};

struct Vec {
    Elem* data;
    int count;

    Elem* Begin() { return data; }
    Elem* End() { return data + count; }
    void Erase(Elem* f, Elem* l) { count -= l - f; }
};

struct Obj {
    void* res;
    char arr[8];
    Vec vec;
};

extern "C" Obj* shared_g_fa02abdc(Obj* self, int del) {
    if (self != 0) {
        Vec* v = &self->vec;
        if (v != 0) {
            if (v != 0) {
                if (v != 0) {
                    if (v->data != 0) {
                        Elem* e = v->End();
                        int n = v->count;
                        v->count -= n;
                        for (; n != 0; n--) {
                            e--;
                            e->~Elem();
                        }
                        fn_8020B5FC(v->data);
                    }
                }
            }
        }
        fn_8020BCD0(self->arr, (void*)shared_g_627244bb, 4, 2);
        if (self != 0) {
            fn_80046040(self->res, 1);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
