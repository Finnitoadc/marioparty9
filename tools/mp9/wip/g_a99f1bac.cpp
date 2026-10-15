struct Node {
    char pad[0xC];
    int field_0C;
};

struct It {
    int first;
    char pad[0x38];
};

struct Obj {
    char pad[0xE8];
    int field_E8;
};

extern "C" Node* fn_8010EFF0(int* p);
extern "C" void fn_80136D10(It* out, Obj* self, int v);
extern "C" int fn_80136980(It* p);
extern "C" void fn_80112530(int* p, int a, int* b);

extern "C" int shared_g_a99f1bac(Obj* self, int unused, int a, int* b) {
    int h = self->field_E8;
    Node* n = fn_8010EFF0(&h);
    if (n == 0) {
        return 0;
    }
    It it;
    fn_80136D10(&it, self, n->field_0C);
    if (it.first == 0) {
        return 0;
    }
    int r = fn_80136980(&it);
    if (r == 0) {
        return 0;
    }
    int v = *b;
    fn_80112530(&r, a, &v);
    return 1;
}
