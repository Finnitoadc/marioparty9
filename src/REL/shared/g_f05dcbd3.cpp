extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_8005CE40(void* self, int flags);

struct Obj {
    int field_0;
};

extern "C" Obj* shared_g_f05dcbd3(Obj* self, int del) {
    if (self != 0) {
        if (&self->field_0 != 0) {
            fn_8005CE40(self, 0);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
