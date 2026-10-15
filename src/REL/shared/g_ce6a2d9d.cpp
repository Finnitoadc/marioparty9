struct Obj;
typedef void (Obj::*Func)();
struct Obj {
    char pad[0x10c];
    Func func;
};
extern "C" void shared_g_ce6a2d9d(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
