struct Obj { char pad[0x3b4]; unsigned char field_3b4; char pad2[0xF]; unsigned field_3c4; };
extern "C" void shared_g_93528f2f(Obj* self, unsigned char v) {
    if (self->field_3b4 != v) {
        self->field_3b4 = v;
        self->field_3c4 |= 8;
    } else {
        self->field_3b4 = v;
    }
}
