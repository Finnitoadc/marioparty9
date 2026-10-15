struct S {
    char pad[0x150];
    int* field_150;
    char pad2[8];
    int field_15C;
};
extern "C" void fn_80060E40(S* self, int b, int c, int d);
extern "C" void shared_g_e9a3d8ef(S* self, int idx, int c) {
    if (self->field_15C != idx) {
        fn_80060E40(self, self->field_150[idx], c, 0);
        self->field_15C = idx;
    }
}
