struct Obj { char pad[0x24]; unsigned char field_24; char pad2[3]; int field_28; int field_2C; };
extern "C" void shared_g_9bd218e9(Obj* self, unsigned char v) {
    self->field_24 = v;
    self->field_28 = 1;
    self->field_2C = 0;
}
