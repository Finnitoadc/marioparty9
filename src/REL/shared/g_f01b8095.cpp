extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80046040(void* p, int v);

struct Obj {
    void* res;
};

extern "C" Obj* shared_g_f01b8095(Obj* self, int del) {
    if (self != 0) {
        fn_80046040(self->res, 1);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
