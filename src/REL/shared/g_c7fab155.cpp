struct Obj {
    char pad[0x30];
    int field_30;
};

extern "C" void shared_g_c7fab155(Obj* self) {
    self->field_30 = -1;
}
