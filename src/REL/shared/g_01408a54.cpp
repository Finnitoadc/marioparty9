struct List {
    char pad[0x4];
    void** items;
    int count;

    void** Begin() { return items; }
    void** End() { return items + count; }
};

extern "C" void shared_g_ac27d302(void* self, int on);

extern "C" void shared_g_01408a54(List* self, int on) {
    for (void** p = self->Begin(); p != self->End(); p++) {
        shared_g_ac27d302(*p, on);
    }
}
