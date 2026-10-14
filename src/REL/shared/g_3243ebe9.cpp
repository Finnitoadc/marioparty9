struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x22C];
    Func func;
};

extern "C" void shared_g_3243ebe9(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
