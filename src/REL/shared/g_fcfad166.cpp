struct T { virtual void v0(); virtual void v1(); };
extern "C" void fn_80060240();
extern "C" void shared_g_fcfad166(T* self) {
    self->v1();
    fn_80060240();
}
