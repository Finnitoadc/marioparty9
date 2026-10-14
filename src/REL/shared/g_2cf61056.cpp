struct Obj {
    int field_0;
    int field_4;
    int n;
};

static inline void sub(int& a, int b) {
    a -= b;
}

extern "C" void shared_g_2cf61056(Obj* self) {
    sub(self->n, self->n);
}
