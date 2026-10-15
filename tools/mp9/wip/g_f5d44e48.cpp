struct Ref { void* ptr; };
struct Item { char pad[0xC]; int field_0C; };
struct Obj { char pad[0xE8]; int field_E8; };
struct List { int v; };
struct Iter { void* field_0; char pad[0x30]; };

extern "C" Obj* fn_80065DA0();
extern "C" unsigned fn_8010F150(List* l);
extern "C" Item* fn_8010F0F0(List* l, unsigned i);
extern "C" void fn_80136D10(Iter* out, Obj* o, int v);
extern "C" void* fn_80136A40(Iter* it);
extern "C" int fn_80111440(Ref* r);

extern "C" int shared_g_f5d44e48() {
    Obj* o = fn_80065DA0();
    int v = o->field_E8;
    List list;
    list.v = v;
    unsigned n = fn_8010F150(&list);
    for (unsigned i = 0; i < n; i++) {
        Iter it;
        fn_80136D10(&it, o, fn_8010F0F0(&list, i)->field_0C);
        Ref r;
        r.ptr = fn_80136A40(&it);
        if (it.field_0 != 0 && r.ptr != 0) {
            return fn_80111440(&r);
        }
    }
    return -1;
}
