extern "C" void fn_80046040(int, int);

struct Obj {
    char pad[0x28];
    int field_28[1];
};

extern "C" void shared_g_67dcf62b(Obj* self) {
    for (int i = 0; i < 1; i++) {
        if (self->field_28[i] != 0) {
            fn_80046040(self->field_28[i], 1);
            self->field_28[i] = 0;
        }
    }
}
