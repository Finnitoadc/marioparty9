struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[8];
    Func func;
};

extern "C" int shared_g_991bb084(Obj* self) {
    return !self->func;
}
