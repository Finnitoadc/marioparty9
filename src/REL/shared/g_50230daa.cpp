struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x14];
    Func func;
};

extern "C" void shared_g_50230daa(Obj* self) {
    (self->*(self->func))();
}
