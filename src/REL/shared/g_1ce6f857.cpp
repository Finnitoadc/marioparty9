struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x14];
    Func func;
};

extern "C" void shared_g_1ce6f857(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
