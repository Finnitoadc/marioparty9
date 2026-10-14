struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};

struct Obj {
    char pad[0x68C];
    float field_68C;
    Vec field_690;
};

extern "C" void shared_g_35c86b6f(Obj* self, float s) {
    self->field_68C = s;
    self->field_690 = Vec(s, s, s);
}
