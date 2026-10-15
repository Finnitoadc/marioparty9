struct Obj {
    char pad[0x2B9];
    unsigned char field_2B9;
    unsigned char field_2BA;
};

extern "C" int shared_g_f459ae72(Obj* self) {
    if (self->field_2B9 == 0) {
        return 0;
    }
    return self->field_2BA != 0;
}
