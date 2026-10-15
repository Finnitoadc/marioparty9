struct S {
    char pad[0x3a8];
    int field_3a8;
};
extern "C" void shared_g_3bebd8a5(S* s, int v) {
    int r;
    if (v < 0) r = 0;
    else if (v > 2) r = 2;
    else r = v;
    s->field_3a8 = r;
}
