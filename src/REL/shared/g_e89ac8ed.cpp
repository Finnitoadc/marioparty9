struct T { virtual ~T(); };
struct Obj { T* field_0; };
extern "C" void shared_g_e89ac8ed(Obj* self, T* n) {
    if (self->field_0 != n) { delete self->field_0; self->field_0 = n; }
}
