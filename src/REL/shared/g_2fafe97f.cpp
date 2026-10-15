struct O { char pad[0xbb]; unsigned char field_bb; };
struct A { char pad[0x58]; O** field_58; unsigned field_5c; };
extern "C" void shared_g_2fafe97f(A* a, int v) {
    for (unsigned i = 0; i < a->field_5c; i++) {
        O* o = a->field_58[i];
        o->field_bb = (o->field_bb & 0xFE) | (unsigned char)v;
    }
}
