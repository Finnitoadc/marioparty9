struct Child {
    int pad[5];
    virtual ~Child();
};

struct Obj {
    Child* field_0;
};

extern "C" void shared_g_dbd468e3(Obj* self, Child* c) {
    Child* old = self->field_0;
    if (c != old) {
        self->field_0 = c;
        delete old;
    }
}
