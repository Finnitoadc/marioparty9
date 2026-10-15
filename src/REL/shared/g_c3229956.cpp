struct S { char pad[0x2C]; int field_2C; };
extern "C" int shared_g_c3229956(S* self) {
    return self->field_2C == 1;
}
