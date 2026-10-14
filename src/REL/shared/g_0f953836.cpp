struct Obj {
    char pad[0x4c];
    int n;
};

static inline void sub(int& a, int b) {
    a -= b;
}

extern "C" void shared_g_0f953836(Obj* self) {
    sub(self->n, self->n);
}
