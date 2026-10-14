struct VObj {
    int field_0[5];
    virtual void Dtor(int del);
};

struct Obj {
    int field_0;
    int field_4;
    int field_8;
    VObj* obj;
};

extern "C" void shared_g_3b5a3f0e(Obj* self) {
    VObj* p = self->obj;
    if (p) {
        p->Dtor(1);
    }
}
