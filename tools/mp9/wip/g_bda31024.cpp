struct Vec { int x, y, z; };
extern "C" Vec lbl_80237470;

struct Inner { char pad[0x120]; Vec v; };
struct Obj { char pad[0x588]; Inner* field_588; };

extern "C" void shared_g_bda31024(Obj* self) {
    Inner* i = self->field_588;
    const Vec* p = &lbl_80237470;
    i->v = *p;
}
