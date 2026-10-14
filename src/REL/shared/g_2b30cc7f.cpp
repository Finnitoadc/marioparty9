struct Entry {
    unsigned short field_0;
    unsigned short field_2;
};

struct Obj {
    char pad0[0xC];
    Entry** field_c;
    char pad10[0x28 - 0x10];
    int field_28;
};

extern "C" unsigned short shared_g_2b30cc7f(Obj* self, int i) {
    if (i >= 0 && i < self->field_28) {
        return self->field_c[i]->field_2;
    }
    return 0;
}
