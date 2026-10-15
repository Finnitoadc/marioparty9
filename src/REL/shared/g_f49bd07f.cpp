extern "C" void fn_80073CD0(int);
extern "C" void fn_80041460(void*, int);
extern "C" void fn_8020B5FC(void*);
extern "C" void fn_8005CE40(void*, int);

struct Inner {
    int pad[6];
    int field_18;
};

struct Ptr {
    Inner* p;
    void Release() {
        Inner* q = p;
        if (q != 0) {
            fn_80073CD0(q->field_18);
            fn_80041460((char*)q + 4, -1);
            fn_80041460(q, -1);
            fn_8020B5FC(q);
        }
    }
};

struct Obj {
    char pad[0x148];
    Ptr ptr;
};

extern "C" Obj* shared_g_f49bd07f(Obj* self, int del) {
    if (self != 0) {
        Ptr* q = &self->ptr;
        if (q != 0) {
            q->Release();
        }
        if (self != 0) {
            fn_8005CE40(self, 0);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
