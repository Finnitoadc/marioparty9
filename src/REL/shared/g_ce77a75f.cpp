struct Obj {
    char pad[0x2C];
    int field_2c;
};
extern "C" int shared_g_ce77a75f(Obj* self) {
    return self->field_2c == 0;
}
