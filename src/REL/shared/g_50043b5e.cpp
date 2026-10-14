extern "C" int fn_8007E570(const char* name, int a, int b);

struct Str {
    unsigned int isPtr : 1;
    unsigned int field_0 : 7;
    char buf[7];
    char* ptr;

    const char* Get() const { return !isPtr ? buf : ptr; }
};

struct Table {
    char pad[0x24];
    Str names[1];
};

struct Entry {
    int used;
    int field_4;
    int handle;
    char pad[0xC];
};

struct Obj {
    char pad[0x28];
    Table* table;
    char pad2[0x93C - 0x2C];
    Entry entries[1];
    int field_954;
};

extern "C" int shared_g_50043b5e(Obj* self, int i) {
    Entry* e = &self->entries[i];
    if (e->used == 0) {
        e->used = 1;
        int r;
        if (self->field_954 != 0) {
            r = -1;
        } else {
            r = fn_8007E570(self->table->names[i].Get(), 1, 0);
        }
        e->handle = r;
    }
    return 1;
}
