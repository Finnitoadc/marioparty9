struct List {
    int field_00;
};
struct Handle {
    int field_00;
};
struct Val {
    int v;
};
struct Obj {
    char pad[0xe8];
    List field_e8;
};
extern "C" unsigned fn_8010F150(List*);
extern "C" int fn_8010F0F0(List*, unsigned);
extern "C" void fn_80136D10(Handle*, Obj*, unsigned);
extern "C" int fn_80136980(Handle*);
extern "C" void fn_80112530(int*, int, int*);
extern "C" int shared_g_170b23d3(Obj* self, int a, int* b) {
    Handle h;
        List list = self->field_e8;
    unsigned n = fn_8010F150(&list);
    for (unsigned i = 0; i < n; i++) {
        if (fn_8010F0F0(&list, i)) {
            fn_80136D10(&h, self, i);
            if (h.field_00 != 0) {
                int p = fn_80136980(&h);
                if (p != 0) {
                    Val v = *(Val*)b;
                    fn_80112530(&p, a, &v.v);
                }
            }
        }
    }
    return 1;
}
