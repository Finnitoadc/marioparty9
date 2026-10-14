struct Obj {
    char pad[0x1D0];
    char field_1D0[0x59C - 0x1D0];
    int field_59C;
};

extern "C" void shared_g_9ee354d6(void* a0, int a1);

extern "C" void shared_g_53e342af(Obj* self, int v) {
    self->field_59C = v;
    shared_g_9ee354d6(self->field_1D0, v);
}
