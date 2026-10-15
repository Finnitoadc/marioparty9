struct O {
    virtual void v0();
    virtual void v1();
    unsigned char field_4;
};
extern "C" void shared_g_b4a77587(O* self) {
    if (self->field_4 == 0) self->v1();
}
