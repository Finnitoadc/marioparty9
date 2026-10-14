struct Obj {
    char pad0[0x4C];
    void (Obj::*field_4C)();
};

extern "C" void shared_g_52e63d9b(Obj* self) {
    if (self->field_4C) {
        (self->*self->field_4C)();
    }
}
