struct Vec { int x, y, z; };
extern "C" Vec lbl_80237470;

struct Inner { char pad[0x120]; Vec v; };
struct Obj { char pad[0x588]; Inner* field_588; };

static inline void copy(Vec* o, Vec* p) {
    int x = p->x;
    int y = p->y;
    o->y = y;
    o->x = x;
    o->z = p->z;
}

extern "C" void shared_g_bda31024(Obj* self) {
    Vec* d = &self->field_588->v;
    Vec* s = &lbl_80237470;
    copy(d, s);
}
