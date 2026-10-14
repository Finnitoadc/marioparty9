extern "C" void fn_800600E0(void* a, void* b);

struct Obj {
    char pad0[0x14];
    void* field_14;
};

extern "C" void shared_g_28dc69d6(Obj* self, void* v) {
    fn_800600E0(self->field_14, v);
}
