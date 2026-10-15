struct Obj {
    char pad[0x38];
    int field_38;
    unsigned char field_3C;
    char pad2[3];
    int field_40;
};

extern "C" int shared_g_c651c0db(Obj* self) {
    if (self->field_3C == 1) {
        return self->field_40;
    }
    return self->field_38;
}
