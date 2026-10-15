extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80046040(void* p, int x);

struct Elem {
    virtual void Dtor(int x);
    int pad;
};

struct Arr {
    Elem* data;
    int count;

    char* Begin() { return (char*)data; }
    char* End() { return (char*)data + count; }
    void Erase(char* f, char* l) { count -= l - f; }
};

struct Obj {
    void* field_0;
    Arr arr;
};

extern "C" Obj* shared_g_e7358246(Obj* self, int del) {
    if (self != 0) {
        Arr* a = &self->arr;
        if (a != 0) {
            if (a != 0) {
                if (a != 0) {
                    Elem* d = a->data;
                    if (d != 0) {
                        Elem* p;
                        int n = a->count;
                        p = d + n;
                        a->Erase(a->Begin(), a->End());
                        while (n != 0) {
                            p--;
                            p->Dtor(-1);
                            n--;
                        }
                        fn_8020B5FC(a->data);
                    }
                }
            }
        }
        if (self != 0) {
            fn_80046040(self->field_0, 1);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
