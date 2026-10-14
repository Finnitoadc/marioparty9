extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_8003E110(void* obj, int flags);

struct Holder {
    void* obj;
};

extern "C" Holder* shared_g_807a1934(Holder* self, int del) {
    if (self != 0) {
        fn_8003E110(self->obj, 1);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
