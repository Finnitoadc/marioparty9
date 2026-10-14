struct Item {
    char pad[0x2C];
    int field_2c;
};

struct Obj {
    char pad[0x23C];
    Item* items[1];
};

extern "C" int shared_g_03f0f2ae(Obj* self, int i) {
    Item* p = self->items[i];
    if (p == 0) {
        return 1;
    }
    return p->field_2c == 0;
}
