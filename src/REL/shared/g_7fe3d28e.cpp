struct Obj {
    char pad[0xC];
    void* field_c;
};

extern "C" bool shared_g_7fe3d28e(Obj* self) {
    return self->field_c != 0;
}
