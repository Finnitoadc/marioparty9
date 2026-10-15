struct S { int f0; int pad[7]; int field_20; int field_24; };
extern "C" void shared_g_2f21f0d8(void* a, void* b);
extern "C" void shared_g_2dc8ff45(char* self, int i, S* s) {
    shared_g_2f21f0d8(self + i * 0x14 + 8, (char*)s + 4);
    s->field_20 = 0;
    s->field_24 = i;
}
