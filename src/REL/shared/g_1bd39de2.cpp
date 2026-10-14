struct Obj {
    char pad0[0x128];
    void (Obj::*field_128)();
};

extern "C" void shared_g_1bd39de2(Obj* self) {
    if (self->field_128) {
        (self->*self->field_128)();
    }
}
