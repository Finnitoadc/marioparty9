struct Obj {
    char pad[0x2c];
    int field_2c;
};

extern "C" int shared_g_4767e7a4(Obj* self) {
    return self->field_2c == 3;
}
