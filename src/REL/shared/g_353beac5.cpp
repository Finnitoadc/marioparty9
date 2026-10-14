struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x210];
    Func func;
};

extern "C" bool shared_g_353beac5(Obj* self) {
    return !self->func;
}
