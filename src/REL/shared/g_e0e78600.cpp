struct Obj {
    int field_0;
    int field_4;
    int field_8;
    void** items;
};

extern "C" void* shared_g_e0e78600(Obj* self, int i) {
    return self->items[i];
}
