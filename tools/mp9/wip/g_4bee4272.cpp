struct Val {
    int field_00;
};

struct Res {
    char pad[0xC];
    int field_0C;
};

struct Handle {
    int field_00;
    char pad[0x38];
};

extern "C" Res* fn_8010EFF0(int* id);
extern "C" void fn_80136D10(Handle* out, void* obj, int a);
extern "C" int fn_80136B20(Handle* h);
extern "C" void fn_80111990(int* h, int a, Val* b);
extern "C" void fn_80110CA0(int* h, int a);

struct Obj {
    char pad[0xE8];
    int field_E8;
};

extern "C" int shared_g_4bee4272(Obj* self, int unused, int a, Val* b) {
    int id = self->field_E8;
    Res* r = fn_8010EFF0(&id);
    if (r == 0) {
        return 0;
    }
    Handle h;
    fn_80136D10(&h, self, r->field_0C);
    if (h.field_00 == 0) {
        return 0;
    }
    int x = fn_80136B20(&h);
    if (x == 0) {
        return 0;
    }
    int v = b->field_00;
    int aa = a;
    fn_80111990(&x, aa, (Val*)&v);
    fn_80110CA0(&x, 0);
    return 1;
}
