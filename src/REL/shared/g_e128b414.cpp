extern "C" int fn_8007CD10(int a, float x, float y);

struct Obj {
    char pad[0xC];
    unsigned char active;
    char pad2[0x17];
    float scale;
};

extern "C" int shared_g_e128b414(Obj* self, int a, float x, float y) {
    if (self->active) {
        return fn_8007CD10(a, x, y * self->scale);
    }
    return -1;
}
