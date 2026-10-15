struct A {
    char pad[0x50];
    unsigned char field_50_0 : 1;
    unsigned char field_50_1 : 1;
    unsigned char field_50_2 : 1;
    unsigned char field_50_3 : 1;
    unsigned char field_50_4 : 1;
    unsigned char field_50_5 : 1;
    unsigned char field_50_6 : 1;
    unsigned char field_50_7 : 1;
};
extern "C" void shared_g_4bd02ed4(A* self, int v) {
    self->field_50_2 = v;
}
