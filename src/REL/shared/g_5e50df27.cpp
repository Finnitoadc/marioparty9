extern "C" void fn_8013A740(void* p, float x, float y, float z);

struct Vec {
    float x, y, z;
};

extern "C" void shared_g_5e50df27(void* p, Vec* v) {
    fn_8013A740(p, v->x, v->y, v->z);
}
