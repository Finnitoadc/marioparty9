struct Inner {
    char pad[0x20];
};

struct Obj {
    Inner* field_0;
};

extern "C" char* shared_g_8957f4ef(Obj* self) {
    return (char*)self->field_0 + 0x20;
}
