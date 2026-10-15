extern "C" unsigned fn_8005DA60();
extern "C" void fn_8005DA50(void* p, int on);

struct Obj {
    char pad[0x15D];
    unsigned char field_15D;
    unsigned char field_15E;
    unsigned char field_15F;
};

extern "C" void shared_g_fb6a8860(Obj* self, int flag) {
    if (self->field_15F != 0) {
        unsigned t = !self->field_15E;
        self->field_15E = t;
        if (!t) {
            unsigned r = fn_8005DA60();
            if (flag != 0 && self->field_15D != 0) {
                fn_8005DA50(self, !r);
            } else if (r != self->field_15D) {
                fn_8005DA50(self, self->field_15D);
            }
        }
    }
}
