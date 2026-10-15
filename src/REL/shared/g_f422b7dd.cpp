struct Vec { float x, y, z; };
struct Obj {
    char pad[0x3C];
    Vec field_3C;
    Vec field_48;
};

extern "C" void shared_g_f422b7dd(Obj* self, Vec* a, Vec* b) {
    a->x = self->field_3C.x;
    a->y = self->field_3C.y;
    a->z = self->field_3C.z;
    b->x = self->field_48.x;
    b->y = self->field_48.y;
    b->z = self->field_48.z;
}
