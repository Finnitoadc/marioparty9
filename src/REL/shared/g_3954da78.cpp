struct Obj {
    char pad[0x8];
    void* field_8;
};

extern "C" void fn_80060180(void* node);

extern "C" void shared_g_3954da78(Obj* self) {
    fn_80060180(self->field_8);
}
