struct Inner {
    int pad[2];
    int field_8;
};

struct Obj {
    char pad[0x148];
    Inner* inner;
};

extern "C" void shared_g_ecc9b07e(Obj* self, int v) {
    self->inner->field_8 = v;
}
