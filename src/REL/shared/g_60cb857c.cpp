struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x48];
    Func func;
};

extern "C" void shared_g_60cb857c(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
