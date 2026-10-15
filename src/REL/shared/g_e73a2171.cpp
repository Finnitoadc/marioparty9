struct Vec {
    float x, y, z;
};

struct Obj {
    char pad[0x14];
    Vec field_14;
};

extern "C" void shared_g_e73a2171(Obj* self, const Vec* v) {
    self->field_14 = *v;
}
