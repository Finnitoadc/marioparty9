struct A { char pad[0x14]; void* field_14; };
struct B { char pad[0x18]; };
extern "C" void shared_g_8ccb1fa9(B* self, A* out) { out->field_14 = (char*)self + 0x18; }
