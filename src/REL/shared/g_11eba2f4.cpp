struct Vec {
    float x, y, z;
};

struct Obj {
    char pad[0x14];
    Vec pos;
    float field_20;
    unsigned char field_24;
    unsigned char field_25;
};

extern "C" unsigned char shared_g_11eba2f4(Obj* self, Vec* pos, unsigned char* b, float* f) {
    pos->x = self->pos.x;
    pos->y = self->pos.y;
    pos->z = self->pos.z;
    *b = self->field_25;
    *f = self->field_20;
    return self->field_24;
}
