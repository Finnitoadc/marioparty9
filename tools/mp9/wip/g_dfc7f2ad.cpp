struct V3 {
    int x, y, z;
};

struct M {
    V3 a;
    V3 b;
};

struct Item {
    char pad[0x10];
    unsigned int idx;
    char pad2[0x44 - 0x14];
    M m;
};

struct Ctx {
    char pad[0xc];
    void* field_c;
};

extern "C" int fn_80065DE0(void* p);
extern "C" int fn_8010EB00(int* it);
extern "C" Item* fn_8010EAA0(int* it, int i);
extern "C" char* fn_80065DA0(void* p);
extern "C" void fn_8016E190(M* dst, M* src, void* p);
extern "C" unsigned int fn_8016F240(void* b, M* m, int* out);

extern "C" unsigned int shared_g_dfc7f2ad(void* unused, Ctx* a, void* b) {
    int it = fn_80065DE0(a->field_c);
    unsigned int count = fn_8010EB00(&it);
    char* base = (char*)it + 0x4c;
    unsigned int lim = *(unsigned int*)(base + *(int*)(base + 0x24));
    char* tbl = *(char**)(fn_80065DA0(a->field_c) + 0xec);
    unsigned int result = 0;
    unsigned int i;
    unsigned int idx;
    for (i = 0; i < count; i++) {
        int out;
        Item* item = fn_8010EAA0(&it, i);
        if (item != 0) {
            idx = item->idx;
        } else {
            idx = 0;
        }
        int x, y, x2, y2;
        M m;
        {
            x = item->m.a.x;
            y = item->m.a.y;
            m.a.y = y;
            m.a.x = x;
            m.a.z = item->m.a.z;
            x2 = item->m.b.x;
            y2 = item->m.b.y;
            m.b.y = y2;
            m.b.x = x2;
            m.b.z = item->m.b.z;
        }
        if (idx < lim) {
            fn_8016E190(&m, &m, tbl + idx * 0x30);
        }
        if (fn_8016F240(b, &m, &out) == 1) {
            result = 1;
        }
    }
    return result;
}
