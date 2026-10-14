struct Elem {
    char pad[0x14];
};

struct Array {
    Elem* data;
    int count;
};

extern "C" Elem* shared_g_2e891893(Array* self) {
    return self->data + self->count;
}
