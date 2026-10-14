struct Item {
    int kind;
};

struct Obj {
    char pad[0x24C];
    Item* item;
    int field_250;
    int field_254;
};

extern "C" int shared_g_0a501a14(Obj* self) {
    Item* p = self->item;
    if (p == 0) {
        return 0;
    }
    if (self->field_254 > 0) {
        return 0;
    }
    return p->kind >= 6;
}
