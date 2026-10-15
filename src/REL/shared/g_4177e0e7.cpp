struct Obj;
typedef void (Obj::*Func)();
struct Obj { char pad[0xc]; Func func; };
extern "C" void shared_g_4177e0e7(Obj* self) {
    if (self->func) (self->*(self->func))();
}
