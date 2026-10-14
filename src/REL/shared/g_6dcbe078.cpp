struct Obj {
    char pad[0x190];
    unsigned char field_190;
};

extern "C" unsigned char shared_g_6dcbe078(Obj* self) {
    return self->field_190;
}
