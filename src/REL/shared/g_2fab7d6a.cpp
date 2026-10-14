struct Obj {
    int ref;
    char pad[0x60];
    virtual void Dtor(int del);
};

extern "C" void shared_g_2fab7d6a(Obj* self) {
    if (--self->ref == 0 && self != 0) {
        self->Dtor(1);
    }
}
