struct S {
    int pad[28];
    int field_70;
};
extern "C" void fn_800612F0(int);
extern "C" void shared_g_d43030f4(S* s) {
    fn_800612F0(s->field_70);
}
