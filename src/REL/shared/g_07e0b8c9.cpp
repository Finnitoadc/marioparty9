struct Color {
    unsigned char r, g, b, a;
};

struct Obj {
    char pad[0x150];
    Color color;
};

extern "C" void shared_g_07e0b8c9(Obj* self, Color* c) {
    self->color.r = c->r;
    self->color.g = c->g;
    self->color.b = c->b;
    self->color.a = c->a;
}
