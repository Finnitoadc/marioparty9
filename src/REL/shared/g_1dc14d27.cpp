struct VObj {
    virtual void Dtor(int del);
};

struct Obj {
    int field_0;
    VObj* obj;
};

extern "C" void shared_g_1dc14d27(Obj* self) {
    VObj* p = self->obj;
    if (p) {
        self->obj = 0;
        if (p) {
            p->Dtor(1);
        }
    }
}
