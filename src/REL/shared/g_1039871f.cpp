struct Entry {
    int field_0;
    int field_4;
};

struct Obj {
    char pad[0x94];
    Entry* entries;
};

extern "C" int shared_g_1039871f(Obj* self, int i) {
    return self->entries[i].field_4;
}
