struct Obj {
    char pad[0x38];
    int field_38;
};
extern "C" int shared_g_d412ca8f(Obj* self) {
    return self->field_38 == 2;
}
