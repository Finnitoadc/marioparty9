struct VObj {
    virtual void Dtor(int del);
};

struct Obj {
    int field_0;
    int field_4;
    int field_8;
    VObj* obj;
};

extern "C" void shared_g_8df7e362(Obj* self) {
    VObj* p = self->obj;
    if (p) {
        p->Dtor(1);
    }
}
