extern "C" void fn_80191CF0(void* a, void* b);

struct Obj {
    char pad[0x118];
    int field_118;
};

extern "C" void* shared_g_1fd9d986(Obj* self, void* x) {
    fn_80191CF0(&self->field_118, x);
    return x;
}
