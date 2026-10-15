struct Raw {
    char pad[0x14];
};
struct Src {
    int pad0[3];
    unsigned flags;
    int pad1;
    char* longName;
    int field_18;
    int field_1c;
};
struct Dst {
    char pad[0x34];
    int field_34;
    int field_38;
    int field_3c;
    int field_40;
    void* field_44;
};
struct Obj {
    char pad[0x2c];
    Raw* src;
};
extern "C" void* fn_8003E230(int);
extern "C" void* fn_8003E910(void*, char*);
extern "C" void fn_8003F4A0(void*, int);
extern "C" void fn_8003F480(void*, int);
extern "C" void shared_g_a6fa8ca4(Obj* self, int i, int j, int a, int b) {
    Src* s = (Src*)((char*)self->src + i * 0x14);
    int t = s->field_1c;
    Dst* d = (Dst*)((char*)self + j * 0x14);
    d->field_34 = t;
    d->field_44 = 0;
    d->field_38 = 0;
    d->field_3c = -1;
    d->field_40 = -1;
    if (d->field_34 == 0) {
        void* p = fn_8003E230(0x3c);
        if (p) {
            char* name = !(s->flags >> 31) ? (char*)s + 0xd : s->longName;
            p = fn_8003E910(p, name);
        }
        d->field_44 = p;
        fn_8003F4A0(p, 0xc);
        fn_8003F480(d->field_44, s->field_18);
        d->field_38 = 1;
        d->field_40 = a;
        d->field_3c = b;
    }
}
