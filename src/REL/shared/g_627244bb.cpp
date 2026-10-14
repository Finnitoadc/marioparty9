extern "C" void fn_8020B5FC(void* ptr);

struct VObj {
    virtual void Dtor(int del);
};

struct PtrHolder {
    VObj* obj;
};

extern "C" PtrHolder* shared_g_627244bb(PtrHolder* self, int del) {
    if (self != 0) {
        if (self->obj != 0) {
            self->obj->Dtor(1);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
