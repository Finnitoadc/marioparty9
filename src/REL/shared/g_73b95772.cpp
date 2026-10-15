struct S { float a, b, c; };
struct O { char pad[0x28]; float f0, f1, f2; unsigned char flag; };
extern "C" void shared_g_73b95772(O* self, S* s) {
    self->f0 = s->a; self->f1 = s->b; self->f2 = s->c; self->flag = 1;
}
