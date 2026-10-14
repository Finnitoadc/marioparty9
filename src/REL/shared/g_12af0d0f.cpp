struct Node {
    char pad[0xC];
    int field_c;
};

struct Res {
    int field_0;
    char pad[0x30];
};

struct Obj {
    char pad[0xE8];
    int field_e8;
};

extern "C" Node* fn_8010EFF0(int* key);
extern "C" void fn_80136D10(Res* r, Obj* o, int v);
extern "C" int fn_80136B20(Res* r);
extern "C" int fn_801118D0(int* h, int a, int b);

extern "C" int shared_g_12af0d0f(Obj* self, int unused, int a, int b) {
    int key = self->field_e8;
    int h;
    Node* n = fn_8010EFF0(&key);
    if (n == 0) {
        return 0;
    }
    Res r;
    fn_80136D10(&r, self, n->field_c);
    if (r.field_0 == 0) {
        return 0;
    }
    h = fn_80136B20(&r);
    if (h != 0) {
        return fn_801118D0(&h, a, b);
    }
    return 0;
}
