struct Obj {
    char pad0[0x150];
    Obj* field_150;
};

extern "C" void fn_8005DA50(Obj* self, int x);

extern "C" void shared_g_6ddf7f0d(Obj* self, int x) {
    fn_8005DA50(self, x);
    if (self->field_150 != 0) {
        fn_8005DA50(self->field_150, x);
    }
}
