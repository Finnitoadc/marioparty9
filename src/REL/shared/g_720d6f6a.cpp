struct Inner {
    char pad[0xC];
    char field_C[4];
};

struct Obj {
    Inner* field_0;
};

extern "C" char* shared_g_720d6f6a(Obj* self) {
    return self->field_0->field_C;
}
