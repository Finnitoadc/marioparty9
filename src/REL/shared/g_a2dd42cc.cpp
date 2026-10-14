extern "C" void fn_80048860(void* p, int v);

struct List {
    int field_0;
    void** items;
    unsigned int count;
    int field_c;
    int value;
};

extern "C" void shared_g_a2dd42cc(List* self, int v) {
    self->value = v;
    for (unsigned int i = 0; i < self->count; i++) {
        fn_80048860(self->items[i], v);
    }
}
