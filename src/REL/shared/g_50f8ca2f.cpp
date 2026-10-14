struct Vec {
    int x, y, z;
};

struct Obj {
    char pad[0x10];
    Vec field_10[1];
};

extern "C" void shared_g_50f8ca2f(Vec* out, const Obj* self, int i) {
    const Vec& r = self->field_10[i];
    *out = r;
}
