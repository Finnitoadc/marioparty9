struct Vec {
    int x, y, z;
};

extern "C" Vec* fn_80060100(void* obj);

struct Obj {
    int field_0;
    int field_4;
    void* field_8;
};

extern "C" void shared_g_e81a5b7e(Vec* out, Obj* o) {
    Vec* p = fn_80060100(o->field_8);
    int x = p->x;
    int y = p->y;
    out->y = y;
    out->x = x;
    out->z = p->z;
}
