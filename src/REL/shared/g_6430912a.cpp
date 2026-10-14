struct Obj {
    char pad[0x8];
    int* data;
};

extern "C" int shared_g_6430912a(Obj* self, int i) {
    return self->data[i];
}
