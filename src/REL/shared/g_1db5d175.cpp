struct B {
    int pad[8];
    int field_20;
};
struct A {
    int field_00;
    B* field_04;
};
extern "C" int shared_g_1db5d175(A* self) {
    return self->field_04->field_20;
}
