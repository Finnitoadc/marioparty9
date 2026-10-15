struct Obj {
    char pad[0x20];
    float field_20;
};

extern "C" float shared_g_85896325(Obj* self) {
    return self->field_20;
}
