struct Obj {
    char pad[8];
    unsigned char field_8;
    unsigned char field_9;
    char pad2[7];
    unsigned char field_11;
};

extern "C" void shared_g_04f57eab(Obj* self) {
    if (self->field_9) {
        self->field_11 = 1;
        self->field_8 = 1;
    }
}
