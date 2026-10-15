extern "C" void fn_800612F0(void* a, void* b, int c, int d);

struct Obj {
    char pad[0x168];
    void** field_168;
};

extern "C" void shared_g_96683174(Obj* self, int idx, int a, int b) {
    fn_800612F0(self, self->field_168[idx], a, b);
}
