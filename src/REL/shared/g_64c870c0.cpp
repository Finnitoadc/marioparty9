extern "C" void fn_80046040(void* res, int flags);

struct Obj {
    char pad[0xC];
    void* field_C;
};

extern "C" void shared_g_64c870c0(Obj* self) {
    fn_80046040(self->field_C, 1);
}
