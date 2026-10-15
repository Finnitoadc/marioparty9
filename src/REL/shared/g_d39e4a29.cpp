struct Obj {
    char pad[0x90];
    int field_90;
};

extern "C" int shared_g_d39e4a29(Obj* self) {
    return self->field_90;
}
