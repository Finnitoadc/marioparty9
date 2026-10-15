extern "C" void shared_g_c77ac150(void*, int);
extern "C" int shared_g_c28ef4b7(void*);
extern "C" void fn_80071590();

struct P {
    char pad[4];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int);
};

struct Obj {
    char pad[0x48];
    P* field_48;
};

extern "C" void shared_g_f161f9bd(Obj* self, int a, int b) {
    self->field_48->v1();
    shared_g_c77ac150(self->field_48, 1);
    self->field_48->v3(1);
    if (b) {
        while (!shared_g_c28ef4b7(self->field_48)) {
            fn_80071590();
        }
    } else {
        shared_g_c77ac150(self->field_48, 0);
    }
}
