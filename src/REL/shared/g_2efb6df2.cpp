struct Elem {
    char pad0[0xF4];
};

struct Obj {
    Elem* field_0;
    int field_4;
};

extern "C" Elem* shared_g_2efb6df2(Obj* self) {
    return self->field_0 + self->field_4;
}
