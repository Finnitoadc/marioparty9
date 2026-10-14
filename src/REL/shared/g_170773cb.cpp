struct Item {
    int type;
};

struct Obj {
    char pad[0x1C];
    Item* items[136];
};

extern "C" int shared_g_170773cb(Obj* self) {
    Item* it;
    int i;
    for (i = 0; i < 136; i++) {
        it = self->items[i];
        if (it != 0 && it->type >= 4 && it->type < 6) {
            return 1;
        }
    }
    return 0;
}
