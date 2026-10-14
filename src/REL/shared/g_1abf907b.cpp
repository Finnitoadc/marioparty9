struct Vec {
    int x, y, z;
};

struct Obj {
    Vec v;
    unsigned char b;
};

extern "C" Obj* shared_g_1abf907b(Obj* self, const Vec* v, const unsigned char* b) {
    unsigned char bv = *b;
    self->v = *v;
    self->b = bv;
    return self;
}
