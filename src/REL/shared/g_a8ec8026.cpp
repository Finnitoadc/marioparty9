struct Obj {
    char pad[0x288];
    unsigned char field_288;
};
extern "C" void shared_g_a8ec8026(Obj* self) {
    self->field_288 = 1;
}
