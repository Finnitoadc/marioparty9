struct Pair {
    int a;
    int b;
};

struct Obj {
    char pad[0x74];
    int field_74;
    int field_78;
    char pad2[0x88 - 0x7c];
    Pair p;
};

static inline void Set(Pair* p, int a, int b) {
    p->a = a;
    p->b = b;
}

extern "C" void shared_g_dd52fee9(Obj* self, int a, int b) {
    self->field_74 = 1;
    self->field_78 = 1;
    Set(&self->p, a, b);
}
