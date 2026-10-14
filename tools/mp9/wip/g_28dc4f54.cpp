// closest: only the first two stores are swapped (target stores +4 before +0)
struct Vec {
    float v[3];
};

extern Vec lbl_80237470;

struct Obj {
    char pad[0x38];
    unsigned char field_38;
    Vec field_3c;
};

extern "C" void shared_g_28dc4f54(Obj* self, unsigned char on) {
    self->field_38 = on;
    if (on == 0) {
        self->field_3c = lbl_80237470;
    }
}
