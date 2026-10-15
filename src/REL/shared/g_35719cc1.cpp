struct Ent {
    int field_00;
    int field_04;
    int field_08;
};
struct Obj {
    char pad[0x29c];
    Ent* field_29c;
    int field_2a0;
};
extern "C" int shared_g_03f0f2ae(Obj*, int);
extern "C" int shared_g_0a501a14(Obj*);
extern "C" int shared_g_35719cc1(Obj* self, int a) {
    if ((unsigned)a > 4) return 1;
    if (a != 4) {
        Ent* end;
        Ent* e;
        int r;
        e = self->field_29c;
        end = e + self->field_2a0;
        r = 1;
        for (; e != end; e++) {
            if (a == e->field_00) {
                r = shared_g_03f0f2ae(self, e->field_04);
                break;
            }
        }
        return r;
    }
    return shared_g_0a501a14(self);
}
