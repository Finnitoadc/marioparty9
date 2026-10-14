extern "C" void fn_80191CC0(float (*m)[4]);

struct M33 {
    float v[3][3];
};

struct Obj {
    char pad[0x10];
    M33 rot;
};

static inline void setRot(float (*m)[4], const M33& r) {
    float a = r.v[0][0], b = r.v[0][1], c = r.v[0][2];
    float d = r.v[1][0], e = r.v[1][1], f = r.v[1][2];
    float g = r.v[2][0], h = r.v[2][1], i = r.v[2][2];
    m[0][0] = a;
    m[1][0] = b;
    m[2][0] = c;
    m[0][1] = d;
    m[1][1] = e;
    m[2][1] = f;
    m[0][2] = g;
    m[1][2] = h;
    m[2][2] = i;
}

extern "C" float (*shared_g_032f8a2f(Obj* self, float (*m)[4]))[4] {
    fn_80191CC0(m);
    setRot(m, self->rot);
    return m;
}
