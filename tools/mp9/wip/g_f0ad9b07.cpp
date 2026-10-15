extern "C" void fn_800419D0(void*, int);
extern "C" void fn_80041A10(void*, int);

struct Arg { int v; };

struct Obj {
    char pad[0x148];
    unsigned char field_148;
    char pad2[3];
    void* field_14c;
    unsigned char field_150;
    unsigned char field_151;
    char pad3[2];
    void (*field_154)(Arg);
    int field_158;
};

extern "C" void shared_g_f0ad9b07(Obj* self) {
    if (self->field_148) {
        fn_800419D0(self->field_14c, 1);
        fn_80041A10(self->field_14c, 0);
        unsigned char t = self->field_150;
        self->field_148 = t;
        if (t == 0) {
            self->field_151 = 1;
        }
        void (*f)(Arg) = self->field_154;
        if (f) {
            Arg a;
            a.v = self->field_158;
            f(a);
        }
    }
}
