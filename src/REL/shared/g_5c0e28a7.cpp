struct Obj {
    char pad[0x24];
    float x;
    float y;
};

extern "C" void shared_g_5c0e28a7(Obj* self, float a, float b) {
    self->x = a;
    self->y = b;
}
