struct Entry {
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    char pad[0x34];
};

struct Obj {
    char pad[0xE8];
    Entry entries[1];
};

extern "C" int shared_g_0292d24c(Obj* self, int i, int a, int b, int c, int d) {
    Entry* e = &self->entries[i - 1];
    e->field_00 = a;
    e->field_04 = b;
    e->field_08 = c;
    e->field_0C = d;
    return 1;
}
