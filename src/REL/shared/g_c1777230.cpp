struct B {
    char pad[0x18];
    int field_18;
};

struct A {
    char pad[0x588];
    B* field_588;
};

extern "C" int shared_g_c1777230(A* self) {
    return self->field_588->field_18;
}
