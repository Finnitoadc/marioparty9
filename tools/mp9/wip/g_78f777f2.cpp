// lwzu r4, lbl@l(r5) not reproduced: compiler emits addi+lwz instead
struct Vec {
    int x, y, z;
};

extern "C" Vec lbl_80237470;

struct Obj {
    char pad[0x230];
    Vec field_230;
};

extern "C" void shared_g_78f777f2(Obj* self) {
    int x = lbl_80237470.x;
    int y = lbl_80237470.y;
    self->field_230.y = y;
    self->field_230.x = x;
    self->field_230.z = lbl_80237470.z;
}
