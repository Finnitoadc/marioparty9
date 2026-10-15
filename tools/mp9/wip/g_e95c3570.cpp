struct Vec {
    float x, y, z;
};
extern "C" Vec lbl_80237470;

struct Obj {
    char pad[0x3C];
    Vec field_3C;
};

extern "C" void shared_g_e95c3570(Obj* self) {
    self->field_3C = lbl_80237470;
}
