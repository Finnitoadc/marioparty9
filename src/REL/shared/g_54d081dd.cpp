struct Obj {
    char pad0[0x8];
    int field_8;
};

extern "C" bool shared_g_54d081dd(Obj* self) {
    return self->field_8 == 5;
}
