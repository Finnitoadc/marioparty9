extern "C" void fn_8020B5FC(void* p);
extern "C" void fn_80071420(void* p, int v);
extern "C" void shared_g_235ab674(void* p, int v);

struct Obj {
    char pad[0x16C];
    int field_16C;
};

extern "C" Obj* shared_g_c106e59c(Obj* self, int del) {
    if (self != 0) {
        fn_80071420(&self->field_16C, 0);
        shared_g_235ab674(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
