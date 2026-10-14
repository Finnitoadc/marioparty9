struct Inner {
    char pad0[0x10];
    unsigned int field_10;
};

struct Obj {
    Inner* field_0;
};

extern "C" unsigned int shared_g_0d0f93e8(Obj* self) {
    return self->field_0->field_10 >> 31;
}
