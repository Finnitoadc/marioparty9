struct S { char pad[0xC]; unsigned short** field_0C; char pad2[0x28 - 0x10]; int field_28; };
extern "C" unsigned short shared_g_9d90e85b(S* self, int idx) {
    if (idx >= 0 && idx < self->field_28) {
        return *self->field_0C[idx];
    }
    return 0;
}
