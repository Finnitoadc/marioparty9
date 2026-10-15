struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x1C];
    unsigned char field_1C;
    char pad2[0x100 - 0x1D];
    Func func;
};

extern "C" void shared_g_b2f7da58(Obj* self) {
    if (self->field_1C != 0) {
        if (self->func) {
            (self->*(self->func))();
        }
    }
}
