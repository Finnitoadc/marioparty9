struct Obj {
    char pad0[0x10];
    void (Obj::*field_10)();
};

extern "C" void shared_g_0ef56565(Obj* self) {
    if (self->field_10) {
        (self->*self->field_10)();
    }
}
