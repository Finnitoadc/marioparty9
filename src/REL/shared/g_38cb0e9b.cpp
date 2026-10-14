extern "C" void fn_80191CF0(void* a, void* b);
extern "C" void fn_80191FE0(void* a, void* b);

struct Obj {
    char pad[0x40];
    unsigned char field_40;
    char pad2[3];
    char sub1[0x30];
    char sub2[4];
};

extern "C" void shared_g_38cb0e9b(Obj* self, void* other) {
    self->field_40 = 1;
    fn_80191CF0(other, self->sub1);
    fn_80191FE0(other, self->sub2);
}
