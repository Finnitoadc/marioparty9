struct C {
    char pad[0x18];
    int field_18;
};

struct B {
    char pad[0x28];
    C* field_28;
};

struct Obj {
    char pad[0xc];
    B** field_c;
};

extern "C" int shared_g_3481c187(Obj* self, int i) {
    C* c = self->field_c[i]->field_28;
    if (c != 0) {
        return c->field_18;
    }
    return 0;
}
