struct List {
    char pad[0x4];
    void** items;
    unsigned int count;
};

extern "C" void shared_g_ac27d302(void* self, int on);

extern "C" void shared_g_01fa4a96(List* self, int on) {
    for (unsigned int i = 0; i < self->count; i++) {
        shared_g_ac27d302(self->items[i], on);
    }
}
