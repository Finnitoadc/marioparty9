struct Obj {
    char pad[0x2C];
    int field_2C;
};

extern "C" int* shared_g_341c8192(Obj* self) {
    return &self->field_2C;
}
