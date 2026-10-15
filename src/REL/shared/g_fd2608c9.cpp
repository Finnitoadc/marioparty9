extern "C" void fn_8009ACF0(void* p);

struct Ref {
    int pad0;
    int count;
};

struct SP {
    int ptr;
    Ref* ref;
};

extern "C" SP* shared_g_fd2608c9(SP* self, const SP* other) {
    int p;
    Ref* r;
    r = other->ref;
    p = other->ptr;
    if (r != 0) {
        r->count++;
    }
    Ref* old = self->ref;
    self->ptr = p;
    self->ref = r;
    if (old != 0) {
        fn_8009ACF0(old);
    }
    return self;
}
