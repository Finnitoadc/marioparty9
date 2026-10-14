struct Vec {
    float x, y, z;
};

struct Obj {
    char pad[0x58];
    Vec field_58;
};

extern "C" void shared_g_07393696(Obj* self, const Vec& v) {
    self->field_58 = v;
}
