struct Src {
    virtual float Get();
};

extern "C" float shared_g_90fba63f(float* a, float* b, Src* s) {
    float t = s->Get();
    float x = *a;
    float d = *b - x;
    d *= t;
    return x + d;
}
