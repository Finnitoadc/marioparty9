struct S { char pad[0x2C]; int field_2C; };
extern "C" int fn_80074EA0();
extern "C" int shared_g_c52882d4(S* self) {
    if (fn_80074EA0()) {
        self->field_2C++;
    }
    return 0;
}
