struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0xf8];
    Func func;
};

extern "C" void shared_g_9e167c18(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
