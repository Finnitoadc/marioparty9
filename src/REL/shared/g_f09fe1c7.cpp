struct Child {
    virtual ~Child();
};

struct Obj {
    char pad[8];
    Child* field_8;
};

extern "C" void shared_g_f09fe1c7(Obj* self) {
    Child* c = self->field_8;
    if (c != 0) {
        self->field_8 = 0;
        delete c;
    }
}
