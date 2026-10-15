struct A { char pad[0x584]; int field_584; };
extern "C" void shared_g_17ec50af(A* a, int v) {
    int r;
    if (v < 0) r = 0;
    else if (v > 2) r = 2;
    else r = v;
    a->field_584 = r;
}
