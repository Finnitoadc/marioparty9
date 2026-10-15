struct Obj {
    char pad[0x14];
    float a, b, c, d;
};

extern "C" float* shared_g_ef31252c(Obj* self, float* out) {
    float d, c, b, a;
    a = self->a;
    b = self->b;
    c = self->c;
    d = self->d;
    out[0] = a;
    out[1] = b;
    out[2] = c;
    out[3] = d;
    return out;
}
