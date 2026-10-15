struct Vec { float x, y, z; };
struct In { char pad[0xc]; int field_c; Vec v; };
struct O { char pad[0x148]; In* field_148; };

extern "C" void shared_g_0f9fb89f(O* self, const Vec& p) {
    In* i = self->field_148;
    i->field_c = -1;
    i->v = p;
}
