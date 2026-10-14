extern "C" void fn_80038790(void* self);

struct Obj {
    char pad[0x48];
    float field_48;
};

extern "C" void shared_g_aa6fa5e5(Obj* self, float x) {
    fn_80038790(self);
    self->field_48 = x;
}
