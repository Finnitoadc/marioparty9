struct Inner {
    char pad[0x38];
    char field_38[4];
};

struct Obj {
    Inner* field_0;
};

extern "C" char* shared_g_6389d58b(Obj* self) {
    return self->field_0->field_38;
}
