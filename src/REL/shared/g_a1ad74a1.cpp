extern "C" void fn_8005DA50(void* self, int on);

struct Obj {
    char pad[0x15D];
    unsigned char field_15d;
};

extern "C" void shared_g_a1ad74a1(Obj* self, unsigned char on) {
    self->field_15d = on;
    fn_8005DA50(self, on);
}
