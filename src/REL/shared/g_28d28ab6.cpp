struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x28];
    Func func;
};

extern "C" void shared_g_28d28ab6(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
