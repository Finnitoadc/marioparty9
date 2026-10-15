struct Obj {
    char pad[0x1D0];
    void* field_1D0;
};

extern "C" void* shared_g_702f1ab6(Obj* self) {
    return self->field_1D0;
}
