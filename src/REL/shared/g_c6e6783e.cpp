struct Ent { char pad[0x14]; };
struct Obj {
    char pad[0x20];
    Ent ent[1];
    char pad2[0x1CC - 0x34];
    int field_1CC;
    char pad3[0x1E8 - 0x1D0];
    int field_1E8;
};
extern "C" int shared_g_c6e6783e(Obj* self, int i) {
    int t = *(int*)((char*)self + 0x34 + i * 0x14);
    if (t == 3) return self->field_1E8;
    if (t == 2) return self->field_1CC;
    return 1;
}
