extern "C" void fn_80086B60(void* a, void* b);

struct Src {
    char pad[0x10];
    int field_10;
    char sub[4];
};

struct Dst {
    int field_0;
    char sub[4];
};

extern "C" void shared_g_b7d21b28(Dst* dst, Src* src) {
    dst->field_0 = src->field_10;
    fn_80086B60(dst->sub, src->sub);
}
