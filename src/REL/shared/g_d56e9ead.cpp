struct Obj {
    char pad[0x10];
    int count;
};

extern "C" int shared_g_d56e9ead(Obj* self) {
    if (self->count == 0) {
        return 0;
    }
    return (self->count - 1) * 0x55;
}
