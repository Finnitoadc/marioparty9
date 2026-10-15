extern "C" void shared_g_d8067967(unsigned a, int b);
struct Obj { unsigned field_0; };
extern "C" void shared_g_912bbd80(Obj* self, unsigned v) {
    unsigned old = self->field_0;
    if (v == old) return;
    self->field_0 = v;
    shared_g_d8067967(old, 1);
}
