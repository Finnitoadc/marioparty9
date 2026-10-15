struct A {
    char pad[0x198];
    int field_198;
};
extern "C" void fn_8005D990(int);
extern "C" void shared_g_2e2d4295(A* self) {
    if (self->field_198 != 0) fn_8005D990(self->field_198);
}
