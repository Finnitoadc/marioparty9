struct Obj { int pad; int* field_4; };
extern "C" void fn_8007D190(int, int);
extern "C" void shared_g_d2a8e0dc(Obj* self, int i, int b) { fn_8007D190(self->field_4[i], b); }
