struct In {
    char pad[0x5c];
    int field_5c;
};

struct Obj {
    char pad[0x588];
    In* field_588;
};

extern "C" void shared_g_ed7a00b6(Obj* self, int v) {
    self->field_588->field_5c = v;
}
