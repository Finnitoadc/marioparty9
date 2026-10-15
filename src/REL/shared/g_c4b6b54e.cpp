struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x3C];
    Func func;
};

extern "C" void shared_g_c4b6b54e(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
