struct Elem {
    char pad[0x18];
    unsigned char field_18;
    char pad2[3];
};

struct Obj {
    char pad[0x40];
    Elem* field_40;
};

extern "C" void shared_g_05bf7457(Obj* self, int i, unsigned char v) {
    self->field_40[i].field_18 = v;
}
