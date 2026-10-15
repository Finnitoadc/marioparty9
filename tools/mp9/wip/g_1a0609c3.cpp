struct O {
    virtual void v0();
    virtual void f();
    float field_4;
    float field_8;
    unsigned char field_c;
};
extern "C" float lbl_8026E3B4;

extern "C" void shared_g_1a0609c3(O* self) {
    if (self->field_c == 0) return;
    float t = self->field_4 + lbl_8026E3B4;
    self->field_4 = t;
    if (self->field_8 <= t) {
        self->field_c = 0;
        self->f();
    }
}
