struct In { char pad[8]; float f8; float fc; };
struct O { char pad[0x148]; In* field_148; };
extern "C" void shared_g_58736b1f(O* o, float v) { o->field_148->f8 = v; o->field_148->fc = v; }
