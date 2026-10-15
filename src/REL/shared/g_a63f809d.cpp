struct Obj;
typedef void (Obj::*Func)();
struct Inner {
    char pad[0x120];
    Func func;
};
struct Obj {
    char pad[0x588];
    Inner* field_588;
};
extern "C" int shared_g_a63f809d(Obj* self) {
    return !!self->field_588->func;
}
