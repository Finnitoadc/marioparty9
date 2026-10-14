struct Obj {
    int field_0;
};

extern "C" void fn_8005CE40(void* self, int del);
extern "C" void fn_8020B5FC(void* p);

extern "C" Obj* shared_g_702e120b(Obj* self, int del) {
    if (self != 0) {
        if (self != 0) {
            if (self != 0) {
                fn_8005CE40(self, 0);
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
