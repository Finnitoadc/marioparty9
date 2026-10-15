struct B {
    char pad[0x20];
    int field_20;
    int field_24;
};

extern "C" void shared_g_2f21f0d8(void* a, void* b);

extern "C" void shared_g_63d174b7(char* self, B* o) {
    shared_g_2f21f0d8(self + 0x10c, (char*)o + 4);
    o->field_24 = 13;
    o->field_20 = 1;
}
