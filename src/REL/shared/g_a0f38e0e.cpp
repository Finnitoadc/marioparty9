struct E { char pad[0xC]; };
struct Obj { E* data; };

extern "C" E* shared_g_a0f38e0e(Obj* self, int i) {
    return &self->data[i];
}
