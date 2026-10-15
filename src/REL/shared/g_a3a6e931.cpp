struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x64];
    Func func;
};

extern "C" void shared_g_a3a6e931(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
