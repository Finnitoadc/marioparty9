struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x190];
    Func func;
};

extern "C" void shared_g_a170066c(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
