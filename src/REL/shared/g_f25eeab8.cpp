struct Obj;
typedef void (Obj::*Func)();
struct Obj {
    char pad[0x100];
    Func func;
};
extern "C" void shared_g_f25eeab8(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
