struct Obj {
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    unsigned char pad[5];
    unsigned char field_9;
};

extern "C" void shared_g_892adbdc(Obj* self) {
    if (self->field_9 != 0) {
        self->v010();
    }
}
