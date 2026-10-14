struct Obj {
    char pad0[0xD0];
    void (Obj::*field_D0)();
};

extern "C" void shared_g_57256b9f(Obj* self) {
    if (self->field_D0) {
        (self->*self->field_D0)();
    }
}
