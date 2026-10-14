extern "C" void fn_8020B5FC(void* p);
extern "C" void fn_80071420(void* p, int x);

struct Buf {
    int* field_0;
    int field_4;
};

struct Obj {
    char pad0[0xC];
    Buf field_C;
};

extern "C" Obj* shared_g_48cc7478(Obj* self, int del) {
    if (self != 0) {
        Buf* b = &self->field_C;
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
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
