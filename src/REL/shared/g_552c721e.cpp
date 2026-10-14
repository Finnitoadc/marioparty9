struct Obj {
    char pad[0x34];
    float field_34;
    float field_38;
    float field_3c;
};

extern "C" void shared_g_552c721e(Obj* self, float x, float y, float z) {
    self->field_34 = x;
    self->field_38 = y;
    self->field_3c = z;
}
