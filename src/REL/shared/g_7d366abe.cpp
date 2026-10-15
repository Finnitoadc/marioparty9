struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x40];
    Func func;
};

extern "C" void shared_g_7d366abe(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
