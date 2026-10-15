struct A {
    char pad[0x10];
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char field_17;
    unsigned char field_18;
};
extern "C" int fn_80070680(int);
extern "C" void fn_8006E100(int);
static inline int Flag(A* a) {
    int f = 0;
    if (a->field_17 != 0 || a->field_18 != 0) f = 1;
    return f;
}
extern "C" void shared_g_b8264522(A* self) {
    int id;
    if (self->field_15 == 0 && Flag(self) != 0) id = -1;
    else id = self->field_10;
    if (id != -1) fn_8006E100(fn_80070680(id));
}
