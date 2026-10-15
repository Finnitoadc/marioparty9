struct V { int x, y, z; };
extern "C" V* fn_80060100(void* p);
extern "C" void shared_g_ef754f1a(V* self, void* p) {
    V* s = fn_80060100(p);
    int y = s->y;
    int x = s->x;
    self->y = y;
    self->x = x;
    self->z = s->z;
}
