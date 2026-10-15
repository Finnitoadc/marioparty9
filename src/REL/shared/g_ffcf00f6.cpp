extern "C" void fn_80162D00(void* p);

struct Obj {
    char pad[0x1C];
    char field_1C;
};

extern "C" void shared_g_ffcf00f6(Obj* self) {
    fn_80162D00(&self->field_1C);
}
