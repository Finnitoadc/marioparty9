struct S {
    int field_0;
    int field_4;
    unsigned char field_8;
};

extern "C" void shared_g_5d4b559d(S* dst, const S* src) {
    *dst = *src;
}
