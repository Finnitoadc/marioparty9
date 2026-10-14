extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_8009ACF0(void* p);

struct Ref {
    int field_0;
    void* p;
};

struct Obj {
    char pad[0xC];
    Ref ref;
};

extern "C" Obj* shared_g_2942426a(Obj* self, int del) {
    if (self != 0) {
        if (&self->ref != 0) {
            if (self->ref.p != 0) {
                fn_8009ACF0(self->ref.p);
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
