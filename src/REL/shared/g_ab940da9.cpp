struct Inner {
    int pad[2];
    int field_8;
};

struct Obj {
    Inner* field_0;
};

extern "C" char* shared_g_ab940da9(Obj* self) {
    Inner* p = self->field_0;
    if (p->field_8 != 0) {
        return (char*)p + p->field_8;
    }
    return 0;
}
