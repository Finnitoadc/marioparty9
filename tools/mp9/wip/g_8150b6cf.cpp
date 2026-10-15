extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80046040(void* res, int flags);
extern "C" void fn_80071420(void* p, int v);

struct Elem {
    virtual void v0(int);
    int field_4;
};

struct Buffer {
    Elem* data;
    int count;

};

struct Res {
    void* p;
};

struct Obj {
    char pad[4];
    int field_4;
    char pad2[4];
    Res field_C;
    Buffer buf;
};

extern "C" Obj* shared_g_8150b6cf(Obj* self, int del) {
    if (self != 0) {
        Buffer* b = &self->buf;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b->data != 0) {
                        Elem* p;
                        int n = b->count;
                        p = &b->data[n];
                        b->count -= n;
                        while (n != 0) {
                            --p;
                            p->v0(-1);
                            --n;
                        }
                        fn_8020B5FC(b->data);
                    }
                }
            }
        }
        Res* r = &self->field_C;
        if (r != 0) {
            fn_80046040(r->p, 1);
        }
        fn_80071420(&self->field_4, 0);
        fn_80046040(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
