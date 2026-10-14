struct Vec {
    float x, y, z;
};

struct Obj {
    char pad[0x19];
    unsigned char field_19;
    char pad2[0x68A];
    unsigned char field_6a4;
    char pad3[3];
    Vec pos;
    float field_6b4;
    float field_6b8;
};

extern "C" void shared_g_620c69e4(Obj* self, const Vec& pos, float t) {
    self->field_19 = 1;
    self->field_6a4 = 1;
    self->pos = pos;
    self->field_6b8 = t;
}
