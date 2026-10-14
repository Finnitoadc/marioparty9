extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* obj, int flags);
extern "C" void fn_80086F10(void* obj, int flags);
extern "C" void fn_8020BCD0(void* arr, void* dtor, int size, int n);
extern "C" void shared_g_627244bb();

struct Handle {
    int field_0;
    char obj[4];
};

struct Obj {
    char pad[0x8];
    Handle handle;
    char pad2[0x8];
    char arr[0x10];
};

extern "C" Obj* shared_g_7ac02ddd(Obj* self, int del) {
    if (self != 0) {
        fn_8020BCD0(self->arr, (void*)shared_g_627244bb, 4, 4);
        Handle* h = &self->handle;
        if (h != 0) {
            fn_80086F10(h->obj, -1);
        }
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
