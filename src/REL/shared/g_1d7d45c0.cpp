struct E { char pad[0x38]; };
struct V { E* data; int count; };
extern "C" E* shared_g_1d7d45c0(V* v) { return v->data + (v->count - 1); }
