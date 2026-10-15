struct Obj { int pad; int* field_4; };
extern "C" int shared_g_da2fd541(Obj* self, int i) { return self->field_4[i]; }
