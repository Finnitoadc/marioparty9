struct Elem {
    int pad[5];
    virtual ~Elem();
};

struct Obj {
    char pad[0x1c];
    Elem* field_1c[0x88];
};

extern "C" void shared_g_62004209(Obj* self) {
    Elem** pp = self->field_1c;
    for (unsigned int i = 0; i < 0x88; i++, pp++) {
        if (self->field_1c[i] != 0) {
            Elem* t = *pp;
            *pp = 0;
            delete t;
        }
    }
}
