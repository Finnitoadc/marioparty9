struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x184];
    Func func;
};

extern "C" void shared_g_ad9da06c(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
