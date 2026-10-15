extern "C" void fn_8003E110(void* p, int a);
struct Obj { char pad[0xc]; void* field_c; };
extern "C" void shared_g_5d35f1fa(Obj* self) { fn_8003E110(self->field_c, 1); }
