struct Out {
    unsigned int* p;
    unsigned int m;
};
struct Obj { unsigned int* data; };
extern "C" void shared_g_a970553f(Obj* self, unsigned int n) {
    volatile Out o;
    unsigned int bit = n & 31;
    unsigned int* d = self->data;
    o.p = d + (n >> 5);
    o.m = 1u << bit;
}
