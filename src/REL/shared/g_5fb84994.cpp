struct Vec {
    float x, y, z;
};

struct Obj {
    char pad[0x34];
    Vec field_34;
};

extern "C" Vec* shared_g_5fb84994(Obj* self, Vec* out) {
    float z;
    float y;
    float x;
    x = self->field_34.x;
    y = self->field_34.y;
    z = self->field_34.z;
    out->x = x;
    out->y = y;
    out->z = z;
    return out;
}
