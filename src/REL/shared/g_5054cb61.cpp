struct Inner {
    char pad[0xA8];
    int field_a8;
};

struct Obj {
    char pad[0x724];
    Inner* field_724;
};

extern "C" void shared_g_5054cb61(Obj* self, int v) {
    if (self->field_724 != 0) {
        self->field_724->field_a8 = v;
    }
}
