struct S {
    char pad[0x28];
    int field_28;
};
extern "C" void shared_g_d7bbb115(S* s, int v) {
    s->field_28 = v;
}
