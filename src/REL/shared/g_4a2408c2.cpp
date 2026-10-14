extern "C" void fn_80191CF0(void* p);

struct Obj {
    char pad[0x6c];
    char field_6c[4];
};

extern "C" void shared_g_4a2408c2(Obj* self) {
    fn_80191CF0(self->field_6c);
}
