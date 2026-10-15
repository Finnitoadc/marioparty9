extern "C" void fn_8005DA50(void*);
struct Obj { char pad[0x14]; void* field_14; };
extern "C" void shared_g_d75ed59f(Obj* self) {
    fn_8005DA50(self->field_14);
}
