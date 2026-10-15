extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80041460(void* p, int v);
extern "C" void fn_80046040(void* res, int flags);
extern "C" void* shared_g_049107ea(void* self, int del);

struct Obj {
    virtual void v0(int);
};

struct Res { void* p; };
struct Hold { Obj* p; };

struct S {
    char pad[0x18];
    Hold field_18;
    Res field_1C;
    char pad2[0x28];
    int field_48;
    int field_4C;
};

extern "C" S* shared_g_c896d3a8(S* self, int del) {
    if (self != 0) {
        fn_80041460(&self->field_4C, -1);
        fn_80041460(&self->field_48, -1);
        Res* r = &self->field_1C;
        if (r != 0) {
            fn_80046040(r->p, 1);
        }
        Hold* h = &self->field_18;
        if (h != 0) {
            Obj* o = h->p;
            if (o != 0) {
                o->v0(1);
            }
        }
        shared_g_049107ea(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
