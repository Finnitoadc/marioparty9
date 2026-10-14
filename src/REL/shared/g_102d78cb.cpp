struct List {
    int field_0;
    int field_4;
    int field_8;
    void** items;
};

struct Obj {
    char pad[0x588];
    List* list;
};

extern "C" void* shared_g_102d78cb(Obj* self, int i) {
    return self->list->items[i];
}
