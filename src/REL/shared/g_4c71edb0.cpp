struct Obj {
    char pad[0x4];
    int field_4;
};

extern "C" int shared_g_4c71edb0(Obj* self) {
    self->field_4++;
    return 1;
}
