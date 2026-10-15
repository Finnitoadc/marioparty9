struct S32 { int d[8]; };
struct It { void* p; char pad[0x2C]; };
struct Ent { char pad[0xC]; int field_C; };

extern "C" int fn_80065DA0(void* p);
extern "C" void* fn_80065DE0(void* p);
extern "C" Ent* fn_8010EFF0(void** it, int key);
extern "C" void fn_80136D10(It* out, int a, int b);
extern "C" void* fn_801368C0(It* it);
extern "C" S32* fn_80110E90(void** it, int idx);

struct Obj { void* field_0; };

extern "C" int shared_g_ddfe9533(Obj* self, int key, int idx, S32* val) {
    int a = fn_80065DA0(self->field_0);
    void* it = fn_80065DE0(self->field_0);
    Ent* e = fn_8010EFF0(&it, key);
    if (e == 0) return 0;
    It r;
    fn_80136D10(&r, a, e->field_C);
    if (r.p == 0) return 0;
    void* q = fn_801368C0(&r);
    S32* d = fn_80110E90(&q, idx);
    for (int i = 0; i < 8; i++) d->d[i] = val->d[i];
    return 1;
}
