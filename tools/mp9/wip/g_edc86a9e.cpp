struct Vec {
    float x, y, z;
};
struct Obj {
    char pad[0x74];
    Vec scale;
};
extern "C" void shared_g_edc86a9e(Obj* self, double s) {
    Vec v;
    v.x = s;
    v.y = s;
    v.z = s;
    float f = (float)s;
    self->scale.x = f;
    self->scale.y = f;
    self->scale.z = f;
    *(volatile Vec*)&v;
}
