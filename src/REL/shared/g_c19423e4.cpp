struct Ent {
    int pad[2];
    int kind;
    int pad2[2];
};

struct Obj {
    char pad[0x34];
    Ent ents[1];
};

struct Obj2 {
    char pad[0x1c4];
    int field_1c4;
    char pad2[0x18];
    int field_1e0;
};

extern "C" int shared_g_c19423e4(char* self, int i) {
    int k = *(int*)(self + i * 0x14 + 0x34);
    if (k == 3) {
        *(int*)(self + 0x1e0) = 3;
    } else if (k == 4) {
        *(int*)(self + 0x230) = 2;
    } else if (k == 2) {
        if (*(int*)(self + 0x1c4) == 1) {
            *(int*)(self + 0x1c4) = 2;
            return 1;
        }
        return 0;
    }
    return 1;
}
