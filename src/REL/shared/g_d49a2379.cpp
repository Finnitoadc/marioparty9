struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x33c];
    Func func;
};

extern "C" void shared_g_d49a2379(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
