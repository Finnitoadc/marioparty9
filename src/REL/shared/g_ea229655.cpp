struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x178];
    Func func;
};

extern "C" void shared_g_ea229655(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
