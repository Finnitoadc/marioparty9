struct D {
    virtual ~D();
};
struct B {
    D* field_00;
};
struct A {
    char pad[0xc];
    B* field_0c;
};
extern "C" void fn_8020B5FC(void*);
extern "C" void shared_g_0707f718(A* self) {
    B* b = self->field_0c;
    if (b != 0) {
        if (b != 0) {
            delete b->field_00;
        }
        fn_8020B5FC(b);
    }
}
