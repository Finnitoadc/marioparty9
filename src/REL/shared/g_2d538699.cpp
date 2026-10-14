struct VObj {
    virtual void* Dtor(int del);
};

struct PtrHolder {
    VObj* obj;
};

extern "C" void* shared_g_2d538699(PtrHolder* self, VObj* value) {
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
