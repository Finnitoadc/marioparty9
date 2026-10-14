struct Vec {
    float x, y, z;
};

struct Obj {
    char pad[0x44];
    Vec field_44;
};

extern "C" void shared_g_164d9d07(Obj* self, Vec* v) {
    Vec* d = &self->field_44;
    d->x = v->x;
    d->y = v->y;
    d->z = v->z;
}
