struct A {
    char pad[0x10];
    int field_10;
    int pad2;
    int pad3;
    int field_1c;
};
extern "C" int shared_g_bb491dd7(A*);
extern "C" void fn_80071590(int);
extern "C" void shared_g_96c848e3(A* self) {
    if (self->field_10 == 6) {
        self->field_1c++;
        fn_80071590(shared_g_bb491dd7(self));
    } else {
        fn_80071590(shared_g_bb491dd7(self));
    }
}
