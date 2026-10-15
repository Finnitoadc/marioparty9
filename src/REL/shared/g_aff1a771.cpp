struct Vec {
    float x, y, z;
};
struct Obj {
    char pad[0x1D4];
    unsigned char field_1d4;
    char pad2[3];
    Vec pos;
};
extern "C" Vec* fn_80060100();
extern "C" void shared_g_aff1a771(Obj* self) {
    Vec* v = fn_80060100();
    self->pos.x = v->x;
    self->pos.y = v->y;
    self->pos.z = v->z;
    self->field_1d4 = 1;
}
