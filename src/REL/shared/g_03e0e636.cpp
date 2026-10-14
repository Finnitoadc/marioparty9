struct Obj {
    char pad[0xD3];
    unsigned char field_D3;
};

extern "C" unsigned char shared_g_03e0e636(Obj* self) {
    return self->field_D3;
}
