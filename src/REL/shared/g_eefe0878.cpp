extern "C" void fn_8003F020(void* p, int x);

struct Obj {
    char pad[0xC];
    void* field_C;
};

extern "C" void shared_g_eefe0878(Obj* self) {
    fn_8003F020(self->field_C, 1);
}
