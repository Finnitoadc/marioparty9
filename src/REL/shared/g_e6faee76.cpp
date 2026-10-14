extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_8009ACF0(void* p);

struct Obj {
    int field_0;
    void* res;
};

extern "C" Obj* shared_g_e6faee76(Obj* self, int del) {
    if (self != 0) {
        if (self->res != 0) {
            fn_8009ACF0(self->res);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
