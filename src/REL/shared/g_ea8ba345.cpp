struct V2 {
    float x, y;
};

extern "C" void shared_g_ea8ba345(V2* v, float s) {
    v->x = v->x * s;
    v->y = v->y * s;
}
