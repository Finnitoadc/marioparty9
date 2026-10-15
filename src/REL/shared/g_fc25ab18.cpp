struct Item {
    char pad[4];
    int field_4;
    char pad2[0x18];
    int field_20;
};
struct Obj {
    char pad[0xC];
    Item** data;
    int count;
};
extern "C" int shared_g_fc25ab18(Obj* self) {
    Item** end = self->data + self->count;
    Item** p = self->data;
    for (; p != end; p++) {
        Item* it = *p;
        if (it->field_20 == 0) return it->field_4;
    }
    return -1;
}
