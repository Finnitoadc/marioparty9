extern "C" void fn_8020B5FC(void* ptr);

struct VObj {
    int field_0[5];
    virtual void Dtor(int del);
};

struct Owner {
    VObj* obj;
};

extern "C" Owner* shared_g_d81af600(Owner* self, int del) {
    if (self != 0) {
        VObj* obj = self->obj;
        if (obj != 0) {
            obj->Dtor(1);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
