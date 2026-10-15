struct In {
    char pad[0x14];
    unsigned char field_14;
};
struct S {
    char pad[0x148];
    In* field_148;
};
extern "C" void shared_g_caeede6d(S* s, unsigned char v) {
    s->field_148->field_14 = v;
}
