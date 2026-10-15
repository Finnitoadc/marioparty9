struct Elem {
    int a;
    int b;
    int c;
};

struct Obj {
    Elem* data;
    int count;
};

extern "C" Elem* shared_g_8b736067(Obj* self) {
    return &self->data[self->count - 1];
}
