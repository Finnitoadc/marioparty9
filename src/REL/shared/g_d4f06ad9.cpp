struct V {
    virtual void v0();
    virtual void v1();
};
struct A {
    char pad[0x338];
    V* field_338;
};
extern "C" void shared_g_d4f06ad9(A* self) {
    self->field_338->v1();
}
