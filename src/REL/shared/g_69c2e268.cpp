struct Sub {
    virtual void Destroy(int del);
};

struct Ptr {
    Sub* p;
    void Release() {
        if (p != 0) {
            p->Destroy(1);
        }
    }
};

struct Obj {
    char pad[0x8];
    Ptr field_8;
    Ptr field_c;
    char arr[8];
};

extern "C" void fn_8020BCD0(void* arr, void* dtor, int size, int n);
extern "C" void shared_g_83da6437();
extern "C" void fn_80086F10(void* p, int del);
extern "C" void fn_8020B5FC(void* p);

extern "C" Obj* shared_g_69c2e268(Obj* self, int del) {
    if (self != 0) {
        fn_8020BCD0(self->arr, (void*)shared_g_83da6437, 4, 2);
        Ptr* p = &self->field_c;
        if (p != 0) {
            p->Release();
        }
        p = &self->field_8;
        if (p != 0) {
            p->Release();
        }
        if (self != 0) {
            fn_80086F10((char*)self + 4, -1);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
