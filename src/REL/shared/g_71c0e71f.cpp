struct Base {
    int field_0;
};

struct VObj : Base {
    virtual void* Dtor(int del);
};

struct PtrHolder {
    VObj* obj;
};

extern "C" void* shared_g_71c0e71f(PtrHolder* self, VObj* value) {
    VObj* old = self->obj;
    if (value == old) {
        return self;
    }
    self->obj = value;
    if (old == 0) {
        return self;
    }
    return old->Dtor(1);
}
