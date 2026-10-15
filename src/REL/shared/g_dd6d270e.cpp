struct S {
    char pad[0x2c];
    unsigned char field_2c;
};
extern "C" unsigned char shared_g_dd6d270e(S* s) {
    return s->field_2c;
}
