struct Obj {
    char pad[0x44];
    void (Obj::*field_44)();
};

extern "C" void shared_g_527efef0(Obj* self) {
    if (self->field_44) {
        (self->*(self->field_44))();
    }
}
