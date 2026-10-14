struct Obj {
    char pad[0xC];
    unsigned char field_C;
};

extern "C" unsigned char shared_g_67da5442(Obj* self) {
    return self->field_C;
}
