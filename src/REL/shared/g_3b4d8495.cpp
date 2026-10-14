struct Obj {
    char pad0[0x38];
    int field_38;
};

extern "C" bool shared_g_3b4d8495(Obj* self) {
    return self->field_38 == 1;
}
