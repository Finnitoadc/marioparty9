struct Obj {
    char pad[0x3c];
    void* field_3c;
};

extern "C" void* shared_g_87cdc474(Obj* self) {
    return self->field_3c;
}
