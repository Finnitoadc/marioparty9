struct Sub {
    char pad[0x10];
    float field_10;
};

struct Obj {
    char pad[0x148];
    Sub* field_148;
};

extern "C" void shared_g_560134cd(Obj* self, float v) {
    self->field_148->field_10 = v;
}
