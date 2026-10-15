struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0xd8];
    Func func;
};

extern "C" void shared_g_d6a88ff8(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
