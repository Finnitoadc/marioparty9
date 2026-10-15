struct A {
    char pad[0x14];
    int field_14;
};
extern "C" void fn_8007F1C0(int);
extern "C" void shared_g_c855356f(A* self) {
    if (self->field_14 != -1) {
        fn_8007F1C0(2);
        self->field_14 = -1;
    }
}
