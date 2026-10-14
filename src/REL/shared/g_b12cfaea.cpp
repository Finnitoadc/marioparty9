struct Obj {
    int state;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018(int x);
};

extern "C" void shared_g_b12cfaea(Obj* self) {
    self->v018(0);
    self->state = 6;
}
