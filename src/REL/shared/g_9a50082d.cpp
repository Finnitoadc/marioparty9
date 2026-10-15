struct Obj {
    char* data;
    int idx;
};

extern "C" char* shared_g_9a50082d(Obj* self) {
    return self->data + self->idx * 16;
}
