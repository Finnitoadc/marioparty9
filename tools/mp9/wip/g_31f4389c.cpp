struct Vec {
    float x, y, z;
};

struct Obj {
    char pad[0x620];
    Vec field_620;
    char pad2[0x763 - 0x62C];
    bool field_763;
    float field_764;
    float field_768;
    char pad3[0x8E8 - 0x76C];
    Vec field_8E8;
    Vec field_8F4;
    float field_900;
    char pad4[0x8];
    int field_90C;
    int field_910;
    char pad5[0x938 - 0x914];
    bool field_938;
    char pad6[0x9A4 - 0x939];
    float field_9A4;
    float field_9A8;
    float field_9AC;
    int field_9B0;

    void Set(const Vec& a, const Vec& b, float f, int n) {
        field_938 = !field_763;
        field_90C = 1;
        field_8E8 = a;
        field_8F4 = b;
        field_900 = f;
        field_910 = n;
    }
};

extern "C" void shared_g_31f4389c(Obj* self) {
    float f = self->field_9AC;
    Vec a = self->field_620;
    Vec b = self->field_620;
    Vec c = self->field_620;
    a.y += self->field_9A4 * self->field_768;
    b.y += self->field_9A8 * self->field_768;
    self->field_938 = !self->field_763;
    self->field_90C = 1;
    self->field_8E8 = a;
    self->field_8F4 = b;
    self->field_900 = f;
    self->field_910 = self->field_9B0;
}
