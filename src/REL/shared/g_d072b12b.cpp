struct Inner {
    char pad[0xC];
    int field_c;
};

struct Obj {
    Inner* inner;
};

extern "C" int shared_g_d072b12b(Obj* self) {
    return self->inner->field_c;
}
