struct VObj {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03(int x);
};

struct Obj : VObj {
    char pad[0x8];
    unsigned char field_c;
    char pad2[2];
    unsigned char field_f;
    char pad3[0x39C];
    unsigned char field_3ac;
};

extern "C" void shared_g_a94ae5ef(Obj* self, unsigned char a, unsigned char b, unsigned char c, int d) {
    self->field_c = a;
    self->field_f = b;
    self->field_3ac = c;
    self->v03(d);
}
