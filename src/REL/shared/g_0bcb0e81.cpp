struct Obj {
    char pad[0x14];
    int field_14;
};

extern "C" int* shared_g_0bcb0e81(Obj* self) {
    return &self->field_14;
}
