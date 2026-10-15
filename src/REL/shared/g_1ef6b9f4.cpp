struct In { char pad[0x14]; int field_14; };
struct O { char pad[0x148]; In* field_148; };
extern "C" void shared_g_1ef6b9f4(O* o, int v) { o->field_148->field_14 = v; }
