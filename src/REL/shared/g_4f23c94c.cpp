extern "C" float fn_8004CA00(float a, float b);

struct Vec {
    float x, y, z;
};

extern "C" float shared_g_4f23c94c(Vec* v) {
    return fn_8004CA00(v->x, v->z);
}
