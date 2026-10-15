struct Obj { float field_0; float field_4; float field_8; };
extern "C" float lbl_8026E3B4;
static inline const float& mn(float x, float y) { return y < x ? y : x; }
extern "C" void shared_g_e5fba225(Obj* self) {
    float a = self->field_8;
    float b = self->field_4 + lbl_8026E3B4;
    self->field_4 = b;
    self->field_4 = mn(b, a);
}
