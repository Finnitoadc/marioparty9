extern "C" void fn_80191CF0(void* p, void* a);

struct Obj {
    char pad0[0x168];
    int field_168;
};

extern "C" void* shared_g_2fc15881(Obj* self, void* a) {
    fn_80191CF0(&self->field_168, a);
    return a;
}
