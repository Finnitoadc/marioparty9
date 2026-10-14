struct Obj {
    char pad0[0x38];
    int field_38;
};

extern "C" bool shared_g_6699dd6d(Obj* self) {
    return self->field_38 == 0;
}
