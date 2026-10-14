extern "C" void shared_g_a2dd42cc(void* self);

struct Target {
    char pad[0x14];
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03(void* p);
};

struct Obj {
    char pad[0x10];
    char* field_10;
    char pad2[0x14];
    Target* field_28;
};

extern "C" void shared_g_6282d0f5(Obj* self) {
    shared_g_a2dd42cc(self);
    if (self->field_28 != 0) {
        self->field_28->v03(self->field_10 + 0x10);
    }
}
