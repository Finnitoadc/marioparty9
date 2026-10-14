struct Obj {
    char pad[0x28];
    int field_28[1];
};

extern "C" void shared_g_0ee4db2f(Obj* self, int i, int v) {
    self->field_28[i] = v;
}
