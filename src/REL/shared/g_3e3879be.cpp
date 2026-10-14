extern "C" void fn_8019C7F0(int* a, int* b, int* c, int* d);
extern "C" void fn_80041550(void* p, int a, int b, int c, int d);
extern "C" void fn_80041A10(void* p, int x);

struct Obj {
    char pad0[0x148];
    int field_148;
};

extern "C" void shared_g_3e3879be(Obj* self) {
    int a, b, c, d;
    fn_8019C7F0(&a, &b, &c, &d);
    fn_80041550(&self->field_148, a, b, c, d);
    fn_80041A10(&self->field_148, 0);
}
