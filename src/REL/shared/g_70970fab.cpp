struct O { char pad[0xC]; float fc; float f10; int f14; int f18; };
extern "C" void shared_g_70970fab(O* o, float* p) {
    float v = *p;
    o->f10 = v; o->fc = v; o->f14 = 0; o->f18 = 1;
}
