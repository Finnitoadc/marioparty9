extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80086F10(void* p, int x);
extern "C" void fn_80071420(void* p, int x);
extern "C" void fn_8005CE40(void* p, int x);

struct Sub {
    char c;
};

struct Inner {
    int pad;
    Sub sub;
};

static inline void DestroySub(Sub* s) {
    fn_80086F10(s, -1);
}

static inline void Destroy(Inner* p) {
    if (p != 0) {
        DestroySub(&p->sub);
    }
}

struct Obj {
    char pad[0x148];
    char field_148;
    char pad2[7];
    Inner field_150;
};

extern "C" Obj* shared_g_934fefd0(Obj* self, int del) {
    if (self != 0) {
        char* q = (char*)&self->field_150;
        if (q != 0) {
            fn_80086F10(q + 4, -1);
        }
        fn_80071420(&self->field_148, 0);
        fn_8005CE40(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
