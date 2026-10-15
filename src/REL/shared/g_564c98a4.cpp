struct Obj {
    char pad[0x20];
    int* field_20;
};

extern "C" int shared_g_564c98a4(Obj* self, int i) {
    return self->field_20[i];
}
