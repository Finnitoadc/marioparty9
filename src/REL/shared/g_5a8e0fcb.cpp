struct In { char pad[0x10]; int field_10; };
struct Obj { char pad[0x148]; In* field_148; };
extern "C" void shared_g_5a8e0fcb(Obj* self, int v) { self->field_148->field_10 = v; }
