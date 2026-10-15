struct Obj {
    char pad[8];
    int field_8;
};

extern "C" int shared_g_a219eb71(Obj* self) {
    return self->field_8 == 2;
}
