struct Obj {
    char pad0[0x620];
    float field_620;
    float field_624;
    float field_628;
    char pad62C[0x768 - 0x62C];
    float field_768;
    char pad76C[0x9A4 - 0x76C];
    float field_9A4;
    float field_9A8;
    float field_9AC;
    int field_9B0;
};

struct Out {
    float field_0;
    float field_4;
    float field_8;
    int field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
};

extern "C" void shared_g_118f3d6e(Obj* self, Out* out) {
    float s = self->field_768;
    float x = self->field_9A4 * s;
    float y = self->field_9A8 * s;
    float py = self->field_624;
    float px = self->field_620;
    float pz = self->field_628;
    float sx = py + x;
    float sy = py + y;
    float z = self->field_9AC;
    int w = self->field_9B0;
    out->field_0 = x;
    out->field_4 = y;
    out->field_8 = z;
    out->field_C = w;
    out->field_10 = px;
    out->field_18 = pz;
    out->field_1C = px;
    out->field_24 = pz;
    out->field_14 = sx;
    out->field_20 = sy;
}
