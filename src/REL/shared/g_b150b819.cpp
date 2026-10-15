struct Obj;
typedef void (Obj::*Func)();
struct Obj {
    char pad[0x2c];
    Func func;
};
extern "C" void shared_g_b150b819(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
