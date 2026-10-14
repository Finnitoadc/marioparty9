extern "C" void fn_80191CF0(void* a, void* b);

struct Obj {
    char pad[0xE8];
    int field_E8;
};

extern "C" void* shared_g_60253ebb(Obj* self, void* x) {
    fn_80191CF0(&self->field_E8, x);
    return x;
}
