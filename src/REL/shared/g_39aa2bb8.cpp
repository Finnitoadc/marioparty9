struct Obj {
    char pad[0x24];
    int field_24;
};

extern "C" void shared_g_39aa2bb8(Obj* self, const int* v) {
    self->field_24 = *v;
}
