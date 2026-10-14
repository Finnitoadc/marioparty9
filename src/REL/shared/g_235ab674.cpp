extern "C" void fn_8020B5FC(void* p);
extern "C" void fn_8005CE40(void* p, int x);

struct Buf {
    int* field_0;
    int field_4;
};

struct Obj {
    char pad0[0x158];
    Buf field_158;
};

extern "C" Obj* shared_g_235ab674(Obj* self, int del) {
    if (self != 0) {
        Buf* b = &self->field_158;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b != 0) {
                        if (b->field_0 != 0) {
                            char* d = (char*)b->field_0;
                            char* end = d + b->field_4;
                            b->field_4 -= (int)(end - d);
                            fn_8020B5FC(d);
                        }
                    }
                }
            }
        }
        fn_8005CE40(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
