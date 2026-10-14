struct Pair {
    void* field_0;
    void* field_4;
};

struct Obj {
    char pad[0x4];
    Pair* field_4;
    char pad2[0x10];
    int field_18;
};

extern "C" void shared_g_ac27d302(void* self, int on);

extern "C" void shared_g_7cb1da5c(Obj* self, int on) {
    if (on) {
        if (self->field_18 >= 0) {
            shared_g_ac27d302(self->field_4->field_4, 0);
            shared_g_ac27d302(self->field_4->field_0, 1);
        } else {
            shared_g_ac27d302(self->field_4->field_4, 1);
            shared_g_ac27d302(self->field_4->field_0, 0);
        }
    } else {
        shared_g_ac27d302(self->field_4->field_4, 0);
        shared_g_ac27d302(self->field_4->field_0, 0);
    }
}
