extern "C" void fn_80041A10(void* p, int v);

struct Obj {
    char pad[0x148];
    void* field_148;
};

extern "C" void shared_g_ce9b1a7d(Obj* self) {
    fn_80041A10(self->field_148, 0);
}
