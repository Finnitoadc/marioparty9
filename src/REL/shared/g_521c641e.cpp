struct Obj;
typedef void (Obj::*Func)();

struct Obj {
    char pad[0x194];
    Func func;
};

extern "C" bool shared_g_521c641e(Obj* self) {
    return !self->func;
}
