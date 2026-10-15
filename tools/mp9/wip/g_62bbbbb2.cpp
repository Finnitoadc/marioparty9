struct Pt { char pad[0x28]; unsigned char field_28; char pad2[0x0f]; void* field_38; char pad3[0x20]; void* field_5c; };
struct Obj {
    char pad0[8];
    void* field_8;
    char pad1[0x44];
    int field_50;
    char pad2[0xe8];
    void* field_138;
    void* field_13c;
    char pad3[0x38];
    void* field_178;
    void* field_17c;
    void* field_180;
};
extern "C" void fn_80048FA0(void* p, int q);

#define F(o) (*(void**)((char*)(o)))

extern "C" void shared_g_62bbbbb2(char* self, int q) {
    fn_80048FA0((char*)*(char**)(self + 0x180) + 8, 0);
    fn_80048FA0(*(void**)(self + 8), 0);
    switch (*(unsigned*)(self + 0x1a0)) {
    case 0: {
        char* p = self;
        for (int i = 0; i < *(int*)(self + 0x50); i++) {
            fn_80048FA0(*(void**)(p + 0xc), 0);
            p += 0x10;
        }
        break;
    }
    case 1: {
        fn_80048FA0(*(void**)(self + 0x138), 0);
        ((Pt*)*(void**)(self + 0x178))->field_28 = 0;
        Pt* t = (Pt*)*(void**)(self + 0x178);
        fn_80048FA0(t, q);
        fn_80048FA0(t->field_38, q);
        fn_80048FA0(t->field_5c, q);
        break;
    }
    case 2: {
        fn_80048FA0(*(void**)(self + 0x118), 0);
        char* p = self;
        for (int i = 0; i < *(int*)(self + 0x50); i++) {
            fn_80048FA0(*(void**)(p + 0x88), 0);
            p += 0x10;
        }
        fn_80048FA0(*(void**)(self + 0x108), 0);
        break;
    }
    case 3: {
        fn_80048FA0(*(void**)(self + 0x148), 0);
        char* p = self;
        for (int i = 0; i < *(int*)(self + 0x50); i++) {
            fn_80048FA0(*(void**)(p + 0x88), 0);
            p += 0x10;
        }
        fn_80048FA0(*(void**)(self + 0x158), 0);
        break;
    }
    case 4: {
        fn_80048FA0(*(void**)(self + 0x118), 0);
        char* p = self;
        for (int i = 0; i < *(int*)(self + 0x50); i++) {
            fn_80048FA0(*(void**)(p + 0xc8), 0);
            p += 0x10;
        }
        fn_80048FA0(*(void**)(self + 0x128), 0);
        break;
    }
    default:
        break;
    }
    fn_80048FA0((char*)*(char**)(self + 0x180) + 8, q);
    fn_80048FA0(*(void**)(self + 8), q);
}
