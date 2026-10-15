extern "C" void fn_8020B5FC(void* p);
extern "C" void fn_80071420(void* p, int v);
extern "C" void fn_80046040(void* p, int v);

struct E {
    virtual void v0(int);
    int x;
};

struct Arr {
    E* data;
    int count;
    E* Begin() { return data; }
    E* End() { return data + count; }
    void Erase(E* f, E* l) { count -= l - f; }
};

struct S {
    int field_0;
    int field_4;
    char pad[0xC];
    Arr arr;
};

extern "C" S* shared_g_d11e5445(S* self, int del) {
    if (self != 0) {
        Arr* b = &self->arr;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b->data != 0) {
                        E* e;
                        int n = b->count;
                        e = b->data + n;
                        b->count -= n;
                        while (n != 0) {
                            --e;
                            e->v0(-1);
                            --n;
                        }
                        fn_8020B5FC(b->data);
                    }
                }
            }
        }
        fn_80071420(&self->field_4, 0);
        fn_80046040(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}