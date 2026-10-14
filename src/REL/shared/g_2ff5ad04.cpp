struct Obj {
    char pad[0x15D];
    unsigned char field_15D;
};

extern "C" unsigned char shared_g_2ff5ad04(Obj* self) {
    return self->field_15D;
}
