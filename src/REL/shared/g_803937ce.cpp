struct A {
    char pad[0x198];
    A* field_198;
};
extern "C" void fn_800600E0(A*, int);
extern "C" void shared_g_803937ce(A* self, int v) {
    fn_800600E0(self, v);
    if (self->field_198 != 0) fn_800600E0(self->field_198, v);
}
