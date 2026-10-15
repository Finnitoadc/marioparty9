struct T { virtual void v0(); virtual void v1(); };
struct Obj { int pad[2]; T* field_8; };
extern "C" void shared_g_d4aa8eb6(Obj* self) {
    self->field_8->v1();
}
