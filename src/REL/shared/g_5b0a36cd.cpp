struct Obj {
    char pad[0x192];
    unsigned char field_192;
};

extern "C" unsigned char shared_g_5b0a36cd(Obj* self) {
    return self->field_192;
}
