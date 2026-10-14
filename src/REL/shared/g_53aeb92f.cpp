struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x18];
    Func func;
};

extern "C" void shared_g_53aeb92f(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
