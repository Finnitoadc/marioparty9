struct Obj {
    char pad[0x7C];
    int field_7C;
    char pad80[0x98 - 0x80];
    int field_98;
};

extern "C" int shared_g_66da2fbd(Obj* self) {
    if (self->field_7C != 0) {
        return 0;
    }
    return self->field_98 == 0x11;
}
