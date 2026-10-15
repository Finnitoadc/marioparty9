struct S { float a, b, c, d; };
struct O { char pad[0x34]; float f0, f1, f2, f3; };
extern "C" void shared_g_f2d48f87(O* self, const S* s) {
    self->f0 = s->a; self->f1 = s->b; self->f2 = s->c; self->f3 = s->d;
}
