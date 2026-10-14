extern "C" void fn_8020BCD0(void*, void*, int, int);
extern "C" void fn_8020B5FC(void*);
extern "C" void shared_g_21cf1dfc();

struct Buf {
    unsigned owned : 1;
    unsigned pad0 : 31;
    int field_4;
    void* data;
};

struct Pair {
    Buf a;
    Buf b;
};

struct Obj {
    char pad[0x20];
    char arr20[8][0xC];
    Pair p80;
    char arr98[0x18][0xC];
};

extern "C" Obj* shared_g_2477a1f4(Obj* self, int del) {
    if (self != 0) {
        fn_8020BCD0(self->arr98, (void*)shared_g_21cf1dfc, 0xC, 0x18);
        Pair* p = &self->p80;
        if (p != 0) {
            if (&p->b != 0) {
                if (p->b.owned) {
                    fn_8020B5FC(p->b.data);
                }
            }
            Buf* a = &p->a;
            if (a != 0) {
                if (a->owned) {
                    fn_8020B5FC(a->data);
                }
            }
        }
        fn_8020BCD0(self->arr20, (void*)shared_g_21cf1dfc, 0xC, 8);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
