struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0xb4];
    Func func;
};

extern "C" void shared_g_b782924f(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
