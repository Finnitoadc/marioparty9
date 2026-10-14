extern "C" void fn_8020B5FC(void* ptr);

struct VObj {
    int field_0[5];
    virtual void Dtor(int del);
};

struct Owner {
    int field_0;
    int field_4;
    VObj* obj;
};

extern "C" Owner* shared_g_c821974a(Owner* self, int del) {
    if (self != 0) {
        VObj** objAddr = &self->obj;
        if (objAddr != 0) {
            VObj* obj = *objAddr;
            if (obj != 0) {
                obj->Dtor(1);
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
