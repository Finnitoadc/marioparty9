struct Obj {
    char pad[0x164];
    int field_164;
};

extern "C" int shared_g_32c784cb(Obj* self) {
    return self->field_164;
}
