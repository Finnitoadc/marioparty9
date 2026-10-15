extern "C" void* fn_8003ECB0(char* name);
extern "C" void fn_8003F480(void* h, int v);
extern "C" void fn_8003F4A0(void* h, int v);
extern "C" unsigned fn_8003F700(void* h);
extern "C" void fn_8003F6E0(void* h, unsigned v);
extern "C" int fn_80060290(int v);
extern "C" void fn_8003F5F0(void* h, int v);

struct Entry {
    int state;
    int pad4;
    unsigned flags;
    int padC;
    char* nameptr;
    int arr14[12];
};

struct Obj2 {
    char pad0[0x28];
    int* field_28;
    char pad2C[0x10];
    int arr3C[2];
    int field_44;
    char pad48[0x60];
    int field_A8;
    char padAC[8];
    Entry e[2];
};

extern "C" void shared_g_ca0c635c(Obj2* self, int idx, int a, int b) {
    Entry* e = &self->e[idx];
    if (e->state == 2) return;
    if (e->state == 0) {
        if (a < b || b == -1) {
            void* h = fn_8003ECB0((e->flags >> 31) == 0 ? (char*)e + 9 : e->nameptr);
            fn_8003F480(h, *self->field_28);
            fn_8003F4A0(h, 0xc);
            fn_8003F6E0(h, fn_8003F700(h) | 1);
            fn_8003F5F0(h, fn_80060290(self->arr3C[self->field_44]));
        }
    } else if (e->state == 1) {
        int v = e->arr14[self->field_A8];
        if (a <= v && b >= v) {
            void* h = fn_8003ECB0((e->flags >> 31) == 0 ? (char*)e + 9 : e->nameptr);
            fn_8003F480(h, *self->field_28);
            fn_8003F4A0(h, 0xc);
            self->field_A8 += 1;
            if (self->field_A8 >= 2) self->field_A8 = 0;
        }
    }
}
