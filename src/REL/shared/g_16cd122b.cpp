extern "C" void fn_8005D990(void* obj);

struct Obj {
    char pad[0x3C];
    void* items[2];
    int index;
};

extern "C" void shared_g_16cd122b(Obj* self) {
    fn_8005D990(self->items[self->index]);
}
