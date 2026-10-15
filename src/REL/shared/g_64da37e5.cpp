struct Obj {
    char pad[0x1C];
    float field_1C;
};

extern "C" float shared_g_64da37e5(Obj* self) {
    return self->field_1C;
}
