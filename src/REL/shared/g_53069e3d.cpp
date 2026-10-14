struct Vec {
    int x, y, z;
};

extern "C" void fn_80062D90(void* a, const char* name, Vec* out);

struct Obj {
    char pad0[0x8];
    unsigned int field_8 : 1;
    char field_9[0x10 - 0x9];
    char* field_10;
    char pad14[0x4C - 0x14];
    Vec field_4C;
    char pad58[0xA4 - 0x58];
    void* field_A4;
};

extern "C" void shared_g_53069e3d(Vec* out, Obj* o, int flag) {
    if (flag != 0 && o->field_A4 != 0) {
        Vec tmp;
        fn_80062D90(o->field_A4, !o->field_8 ? o->field_9 : o->field_10, &tmp);
        int x = tmp.x;
        int y = tmp.y;
        out->y = y;
        out->x = x;
        out->z = tmp.z;
    } else {
        int x = o->field_4C.x;
        int y = o->field_4C.y;
        out->y = y;
        out->x = x;
        out->z = o->field_4C.z;
    }
}
