struct In { int field_0; };
struct Obj { int pad; In* field_4; };
extern "C" void fn_8002C670(int);
extern "C" void shared_g_38d85c4d(Obj* self) { fn_8002C670(self->field_4->field_0); }
