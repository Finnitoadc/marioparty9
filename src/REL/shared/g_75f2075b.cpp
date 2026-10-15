extern "C" void fn_8020BCD0(void*, void*, int, int);
extern "C" void fn_8020B5FC(void*);
extern "C" void shared_g_21cf1dfc();
extern "C" void shared_g_90031b8e();

struct Buf {
    unsigned owned : 1;
    unsigned pad0 : 31;
    int field_4;
    void* data;
};

struct Obj {
    Buf a;
    Buf b;
    Buf c;
    char arr24[1][0xC];
    char arr30[0x10][0xC];
    char arrf0[0x50][0x38];
};

extern "C" Obj* shared_g_75f2075b(Obj* self, int del) {
    if (self != 0) {
        fn_8020BCD0(self->arrf0, (void*)shared_g_90031b8e, 0x38, 0x50);
        fn_8020BCD0(self->arr30, (void*)shared_g_21cf1dfc, 0xC, 0x10);
        fn_8020BCD0(self->arr24, (void*)shared_g_21cf1dfc, 0xC, 1);
        if (&self->c != 0) {
            if (self->c.owned) fn_8020B5FC(self->c.data);
        }
        if (&self->b != 0) {
            if (self->b.owned) fn_8020B5FC(self->b.data);
        }
        if (&self->a != 0) {
            if (self->a.owned) fn_8020B5FC(self->a.data);
        }
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
