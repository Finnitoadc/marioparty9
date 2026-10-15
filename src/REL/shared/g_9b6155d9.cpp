struct Obj {
    int* data;
};

extern "C" int shared_g_9b6155d9(Obj* self, int idx) {
    return self->data[idx];
}
