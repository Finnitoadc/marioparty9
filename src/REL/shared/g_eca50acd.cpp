extern "C" void fn_8020B5FC(void*);
extern "C" void fn_80086F10(void*, int);
extern "C" void shared_g_69c2e268(void*, int);

struct Vec {
    char* data;
    int count;
    char* Begin() { return data; }
    char* End() { return data + count; }
    void Erase(char* f, char* l) { count -= l - f; }
    void Clear() { Erase(Begin(), End()); }
    void Free() {
        if (data != 0) {
            Clear();
            fn_8020B5FC(data);
        }
    }
};

struct Inner {
    char pad[0x34];
    int field_34;
    int field_38;
    Vec v;
};

struct Obj {
    Inner* p;
};

extern "C" Obj* shared_g_eca50acd(Obj* self, int del) {
    if (self != 0) {
        char** e;
        Inner* p = self->p;
        if (p != 0) {
            char** i = (char**)p->v.data;
            e = i + p->v.count;
            for (; i != e; i++) shared_g_69c2e268(*i, 1);
            p->v.Clear();
            Vec* v = &p->v;
            if (v != 0) {
                if (v != 0) {
                    if (v != 0) {
                        if (v != 0) {
                            v->Free();
                        }
                    }
                }
            }
            int* q = &p->field_34;
            if (q != 0) {
                fn_80086F10(q + 1, -1);
            }
            fn_8020B5FC(p);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
