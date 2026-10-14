struct Obj {
    char pad[0xCC];
    int field_CC;
};

extern "C" bool shared_g_32230d14(Obj* self) {
    return self->field_CC != -1;
}
