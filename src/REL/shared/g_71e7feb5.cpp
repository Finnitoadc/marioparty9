struct Vec { float x, y, z; };
struct I { virtual void v0(); virtual void v1(); virtual void* f(); };
struct In { I* field_0; int pad; Vec pos; };
struct O { char pad[0x1c]; In* field_1c; };
extern "C" void fn_800600E0(void* a, Vec* b);

extern "C" void shared_g_71e7feb5(O* self, Vec* v) {
    In* p = self->field_1c;
    fn_800600E0(p->field_0->f(), v);
    p->pos.x = v->x;
    p->pos.y = v->y;
    p->pos.z = v->z;
}
