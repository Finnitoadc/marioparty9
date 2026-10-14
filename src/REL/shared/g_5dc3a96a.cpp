struct Obj {
    char pad[0x30];
    int field_30;
};

extern "C" void shared_g_5dc3a96a(Obj* self, int v) {
    self->field_30 = v;
}
