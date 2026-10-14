struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x98];
    Func func;
};

extern "C" void shared_g_6750f80c(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
