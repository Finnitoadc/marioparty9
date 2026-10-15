extern "C" void fn_8020B5FC(void*);
extern "C" void fn_8002C0A0(void* obj, int flags);

struct Obj {
    int field_0;
};

extern "C" Obj* shared_g_87c25471(Obj* self, int del) {
    if (self != 0) {
        fn_8002C0A0(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
