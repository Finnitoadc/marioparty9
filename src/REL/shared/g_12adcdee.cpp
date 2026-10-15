struct Vec {
    float x, y, z;
};

struct Target {
    char pad[0x2C];
    float x, y, z;
};

extern "C" Target* fn_800486E0();

extern "C" void shared_g_12adcdee(void* self, Vec* v) {
    Target* t = fn_800486E0();
    t->x = v->x;
    t->y = v->y;
    t->z = v->z;
}
