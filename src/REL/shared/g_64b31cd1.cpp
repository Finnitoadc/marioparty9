struct Obj {
    char pad[0x6C];
    int field_6C;
};

extern "C" int shared_g_64b31cd1(Obj* self) {
    return self->field_6C;
}
