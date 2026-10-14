extern "C" int fn_8007E570(int, int, int);

struct Arg {
    int field_0;
    int field_4;
};

struct Obj {
    char pad[0x2C];
    int field_2C;
    int field_30;
};

extern "C" int shared_g_2acd7675(Obj* self, Arg* arg) {
    self->field_30 = fn_8007E570(arg->field_4, 1, 0);
    self->field_2C++;
    return 0;
}
