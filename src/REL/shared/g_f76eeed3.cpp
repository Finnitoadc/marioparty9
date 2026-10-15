struct Q { int v0, v1, v2, v3, v4, v5, v6, v7; };
struct Obj { char pad[0xE8]; int field_E8; };
struct R { char pad[0xC]; void* field_C; };
struct S { int field_0; char pad[0x3C]; };

extern "C" R* fn_8010EFF0(int* p);
extern "C" void fn_80136D10(S* out, Obj* o, void* x);
extern "C" int fn_801368C0(S* s);
extern "C" Q* fn_80110E90(int* p, int idx);

extern "C" int shared_g_f76eeed3(Obj* self, int unused, int idx, Q* src) {
    int a = self->field_E8;
    R* r = fn_8010EFF0(&a);
    if (r == 0) return 0;
    S s;
    fn_80136D10(&s, self, r->field_C);
    if (s.field_0 == 0) return 0;
    int b = fn_801368C0(&s);
    Q* d = fn_80110E90(&b, idx);
    d->v0 = src->v0;
    d->v1 = src->v1;
    d->v2 = src->v2;
    d->v3 = src->v3;
    d->v4 = src->v4;
    d->v5 = src->v5;
    d->v6 = src->v6;
    d->v7 = src->v7;
    return 1;
}
