struct Vec { float x, y, z; };
struct O {
    char pad[0x84];
    unsigned char field_84;
    char pad2[3];
    unsigned field_88;
    unsigned field_8c;
    Vec field_90;
    char pad3[0x24];
    Vec field_c0;
};
extern "C" void fn_80191D30(void* dst, const void* src);

extern "C" int shared_g_3e57529e(O* self, unsigned a, void* out) {
    if (a == self->field_88) {
        fn_80191D30(out, &self->field_90);
    } else if (self->field_84 == 1 && a == self->field_8c) {
        fn_80191D30(out, &self->field_c0);
    }
    return 1;
}
