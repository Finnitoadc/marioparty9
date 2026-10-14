extern "C" void fn_80191CF0(void* a, void* b);
extern "C" void fn_80191FE0(void* a, void* b);

struct Obj {
    char pad0[0x6C];
    char field_6c[0x30];
    char field_9c[0x30];
};

extern "C" void shared_g_5866184e(Obj* self, void* a) {
    fn_80191CF0(a, self->field_6c);
    fn_80191FE0(a, self->field_9c);
}
