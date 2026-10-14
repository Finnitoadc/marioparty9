extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_8003F020(void* obj, int flags);

struct Holder {
    void* obj;
};

extern "C" Holder* shared_g_83da6437(Holder* self, int del) {
    if (self != 0) {
        fn_8003F020(self->obj, 1);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
