extern "C" void fn_80041A10(void* p, int v);

struct Obj {
    char pad[0x148];
    char field_148[4];
};

extern "C" void shared_g_db301fbb(Obj* self) {
    fn_80041A10(self->field_148, 0);
}
