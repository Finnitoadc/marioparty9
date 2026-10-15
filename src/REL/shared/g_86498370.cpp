extern "C" void* memmove(void* dst, const void* src, unsigned n);

struct Iter {
    int* cur;
    int* base;
    int* first;
    int* end;
};

struct Ring {
    int* data;
    unsigned start;
    unsigned count;
    unsigned cap;
};

extern "C" void shared_g_86498370(Ring* self, Iter* a, Iter* b) {
    int* dst = self->data + (self->start + self->count) % self->cap;
    int* ac;
    int* bc = b->cur;
    ac = a->cur;
    if (ac <= bc) {
        memmove(dst, ac, (bc - ac) * 4);
        self->count += b->cur - a->cur;
    } else {
        int bytes = (a->end - ac) * 4;
        memmove(dst, ac, bytes);
        memmove((char*)dst + bytes, b->base, (b->cur - b->base) * 4);
        self->count += (a->end - a->cur) + (b->cur - b->base);
    }
}
