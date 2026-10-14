extern "C" void fn_80074D70(int);

struct Obj {
    char pad[0x2C];
    int field_2C;
};

extern "C" int shared_g_19740b2a(Obj* self) {
    fn_80074D70(0);
    self->field_2C++;
    return 0;
}
