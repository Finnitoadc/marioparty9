struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[8];
    Func func;
};

extern "C" void shared_g_e97d037f(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
