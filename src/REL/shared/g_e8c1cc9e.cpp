struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0xC4];
    Func func;
};

extern "C" void shared_g_e8c1cc9e(Obj* self) {
    if (self->func) {
        (self->*(self->func))();
    }
}
