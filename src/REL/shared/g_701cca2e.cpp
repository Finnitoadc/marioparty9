struct Obj {
    char pad[0x14];
    void* field_14;
};

extern "C" int shared_g_701cca2e(Obj* self) {
    return self->field_14 != 0;
}
