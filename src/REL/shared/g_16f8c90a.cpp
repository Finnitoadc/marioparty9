struct Inner {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
};

extern "C" void shared_g_16f8c90a(Inner** self, int on) {
    Inner* p = *self;
    if (on) {
        p->field_c = 0xF;
    } else {
        p->field_c = 0;
    }
}
