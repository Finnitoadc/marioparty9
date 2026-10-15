struct Vec { float x, y, z; };
struct Obj {
    char pad[0x28];
    float field_28, field_2C, field_30, field_34;
    unsigned char field_38, field_39;
};

extern "C" unsigned char shared_g_d7ee25f0(Obj* self, Vec* v, unsigned char* a, float* f) {
    v->x = self->field_28;
    v->y = self->field_2C;
    v->z = self->field_30;
    *a = self->field_39;
    *f = self->field_34;
    return self->field_38;
}
