struct Entry {
    char data[0xC];
};

struct Table {
    unsigned short field_0;
    unsigned short count;
    int field_4;
    int field_8;
    Entry* entries;
};

struct Ref {
    Table* table;
    Entry* entry;
};

extern "C" void shared_g_1e01b9b4(Ref* out, Table* t, int i) {
    if (i < t->count && i >= 0) {
        Entry* e = &t->entries[i];
        out->table = t;
        out->entry = e;
    } else {
        out->table = t;
        out->entry = 0;
    }
}
