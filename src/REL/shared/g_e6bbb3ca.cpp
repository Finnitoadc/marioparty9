extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_8020BCD0(void* arr, void* dtor, int size, int n);
extern "C" void shared_g_21cf1dfc();

struct Str {
    unsigned flags;
    int field_4;
    void* buf;
};

struct O {
    Str s0;
    Str s1;
    Str s2;
    Str arr[8];
    Str s3;
    Str s4;
};

extern "C" O* shared_g_e6bbb3ca(O* self, int del) {
    if (self != 0) {
        if (&self->s4 != 0) {
            if ((self->s4.flags >> 31) != 0) fn_8020B5FC(self->s4.buf);
        }
        if (&self->s3 != 0) {
            if ((self->s3.flags >> 31) != 0) fn_8020B5FC(self->s3.buf);
        }
        fn_8020BCD0(self->arr, (void*)shared_g_21cf1dfc, 12, 8);
        if (&self->s2 != 0) {
            if ((self->s2.flags >> 31) != 0) fn_8020B5FC(self->s2.buf);
        }
        if (&self->s1 != 0) {
            if ((self->s1.flags >> 31) != 0) fn_8020B5FC(self->s1.buf);
        }
        if (&self->s0 != 0) {
            if ((self->s0.flags >> 31) != 0) fn_8020B5FC(self->s0.buf);
        }
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
