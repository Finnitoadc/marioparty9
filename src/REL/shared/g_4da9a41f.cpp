struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x198];
    Func func;
};

extern "C" void shared_g_4da9a41f(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
