extern "C" void fn_8005D970(void* obj, int mask);

struct Obj {
    char pad[0x3C0];
    unsigned field_3C0;
    unsigned field_3C4;
};

extern "C" void shared_g_e2a19d4a(Obj* self, unsigned v) {
    int bit;
    int m = 0;
    int i;
    if (v != self->field_3C0) {
        for (i = 0; i < 13; i++) {
            bit = 1 << i;
            if (v & bit) {
                m = bit;
            }
        }
        fn_8005D970(self, m);
        self->field_3C0 = v;
        self->field_3C4 |= 8;
    }
}
