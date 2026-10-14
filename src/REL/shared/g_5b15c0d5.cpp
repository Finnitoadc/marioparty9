struct Obj {
    char pad[0x194];
    void (Obj::*field_194)();
};

extern "C" void shared_g_5b15c0d5(Obj* self) {
    if (self->field_194) {
        (self->*(self->field_194))();
    }
}
