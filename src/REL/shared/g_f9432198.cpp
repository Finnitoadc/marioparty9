struct S { char pad[0x2C]; int* field_2C; };
extern "C" void shared_g_f9432198(S* self, int idx, int val) {
    self->field_2C[idx] = val;
}
