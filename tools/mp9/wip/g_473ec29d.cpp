struct Entry {
    int kind;
    int value;
    int field_8;
};

struct Obj {
    char pad[0x18];
    int type;
    Entry* entries;
    int count;
    Entry& At(int i) { return entries[i]; }
};

struct Arg {
    int field_0;
    int value;
};

extern "C" int shared_g_473ec29d(Obj* self, Arg* arg, int start) {
    int def = arg->value;
    if ((unsigned int)self->type <= 2 || self->type == 5) {
        return def;
    }
    int n = self->count;
    for (int i = start; i < n; i++) {
        Entry e = self->At(i);
        if (e.kind != 0x25 && e.kind != 6) {
            return e.value;
        }
    }
    return def;
}
