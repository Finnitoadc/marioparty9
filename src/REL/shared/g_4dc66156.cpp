struct S { char pad[0x10]; int field_10; };
extern "C" int shared_g_4dc66156(S* s) {
    return s->field_10 >= 4;
}
